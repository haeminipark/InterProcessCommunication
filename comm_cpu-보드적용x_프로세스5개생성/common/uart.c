/**    
    @file     uart.c
    @date     2009-03-19
    @author   오재경 freefrug@falinux.com
    @brief    uart 를 사용한 통신을 담당한다.

    @modify   
    @todo    
    @bug     
    @remark   
    
    @warning 
*/
//
//  저작권    에프에이리눅스(주)
//            외부공개 금지
//
//----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/un.h> 
#include <termios.h>

#include <pollmng.h>
#include <uart.h>

poll_obj_t  *uart_open( char *dev_name, int baud, char parity );
int  uart_write( poll_obj_t *obj, char *buf, int len );


char desc_uart[] = "falinux uart ver 0.2.0";


/// uart 개별 구조체
typedef struct {

	// 버퍼관리
	char  recv_fifo[UART_RECV_FIFO_MAX];	
	int   fifo_rcnt;

	char  port[256];
	
} uart_priv_t;


//------------------------------------------------------------------------------
/** @brief    uart 을 open 한다.
    @param    fname  문자열 파일이름
    @return   poll_obj_t 형태의 포인터
*///----------------------------------------------------------------------------
poll_obj_t  *uart_open( char *dev_name, int baud, char parity )
{
	int	fd;
	poll_obj_t  *obj;
	uart_priv_t *uart;
	struct termios  newtio;

	// 시리얼포트를 연다.	
	fd = open( dev_name, O_RDWR | O_NOCTTY );
	if ( fd < 0 ) 
	{
		// 화일 열기 실패
		printf( "device open fail %s : ", dev_name );
		perror("");
		return NULL;
	}
    	
	// 시리얼 포트 환경을 설정한다.
	memset(&newtio, 0, sizeof(newtio) );
	
	// data 8bit
	newtio.c_cflag = CS8 | CLOCAL | CREAD;	// NO-rts/cts
	
	// baud
	switch( baud )
	{
	case 2400   : newtio.c_cflag |= B2400  ; break;
	case 4800   : newtio.c_cflag |= B4800  ; break;
	case 9600   : newtio.c_cflag |= B9600  ; break;
	case 19200  : newtio.c_cflag |= B19200 ; break;
	case 38400  : newtio.c_cflag |= B38400 ; break;
	case 57600  : newtio.c_cflag |= B57600 ; break;
	default     : newtio.c_cflag |= B115200; break;
	}

	// parity	
	switch( parity | 0x20 ) // 소문자 처리
	{
	case 'o'  : newtio.c_cflag  |= (PARENB |PARODD );  break;
	case 'e'  : newtio.c_cflag  |= PARENB           ;  break;
	default   :                                     ;  break;
	}

	newtio.c_iflag      = 0;	
	newtio.c_oflag      = 0;
	newtio.c_lflag      = 0;
	newtio.c_cc[VTIME]  = 0;  
	newtio.c_cc[VMIN]   = 0;  
	
	tcflush  ( fd, TCIFLUSH );
	tcsetattr( fd, TCSANOW, &newtio );
	    
	// uart 만의 정보를 설정한다.
	uart = (uart_priv_t *)malloc( sizeof(uart_priv_t) );
	memset( (void *)uart, 0, sizeof(uart_priv_t) );
	strcpy( uart->port, dev_name );

	obj = poll_add( fd );
	obj->type = STYP_UART;
	obj->priv = (void *)uart;
	
	return obj;
}
//------------------------------------------------------------------------------
/** @brief    uart 를 close 한다.
    @param    obj  폴객체 포인터
*///----------------------------------------------------------------------------
void uart_close( poll_obj_t *obj )
{
	close( obj->fd );
	
	if ( obj->priv )
	{
		free( obj->priv );
	}
	
	poll_delete( obj );
}
//------------------------------------------------------------------------------
/** @brief    uart 폴객체를 파일이름으로 찾는다.
    @param    fname 문자열 파일이름
    @return   obj  폴객체 포인터
*///----------------------------------------------------------------------------
poll_obj_t *uart_get_byport( char *fname )
{
	poll_obj_t *obj;
	uart_priv_t *uart;
	int  idx, count;
	
	count = poll_count();
	
	for(idx=0; idx<count; idx++)
	{
		obj = poll_get_obj( idx );
		if ( obj->type == STYP_UART )
		{
			uart = (uart_priv_t *)obj->priv;  
			if ( uart )
			{
				if ( 0 == strcmp( uart->port, fname ) )
				{
					return obj;
				}
			}
		}
	}
	
	return NULL;
}
//------------------------------------------------------------------------------
/** @brief    uart 를 통해 데이타를 전송한다.
    @param    obj  폴객체 포인터
    @param    buf  전송버퍼
    @param    len  버퍼의 길이
    @return   전송한 데이타 개수
*///----------------------------------------------------------------------------
int  uart_write( poll_obj_t *obj, char *buf, int len )
{
	int  wrcnt;
	
	// 전송한다.
	wrcnt = write( obj->fd, buf, len );

	if ( 0 > wrcnt )
	{
		perror( "uart send error:" );	
	}
	
	return wrcnt;
}
//------------------------------------------------------------------------------
/** @brief    uart 를 통해 데이타를 읽는다.
    @param    obj  폴객체 포인터
    @param    buf  일기버퍼
    @param    len  버퍼의 길이
    @return   읽은 데이타 개수
*///----------------------------------------------------------------------------
int  uart_read( poll_obj_t *obj, char *buf, int len )
{
	int  rdcnt;

	// 데이타를 읽는다.
	rdcnt = read( obj->fd, buf, len );
	
	if ( 0 > rdcnt )
	{
		perror( "uart recv error:" );
	}
	
	return rdcnt;
}
//------------------------------------------------------------------------------
/** @brief    uart 내부 수신버퍼에 데이타를 저장한다.
    @param    obj  폴객체 포인터
    @return   내부수신버퍼의 총 데이타 길이
*///----------------------------------------------------------------------------
int  uart_read_into_fifo( poll_obj_t *obj )
{
	uart_priv_t *uart;
	char *buf;
	int   rdcnt, len;
	
	uart = (uart_priv_t *)obj->priv;  
	buf  = uart->recv_fifo + uart->fifo_rcnt;
	len  = UART_RECV_FIFO_MAX - uart->fifo_rcnt;
	if ( 0 >= len )
	{
		printf( "uart recv buffer full\n" );
	}
	else
	{
		rdcnt = read( obj->fd, buf, len );
		if ( 0 < rdcnt )
		{
			uart->fifo_rcnt += rdcnt;
		}
	}
	
	return uart->fifo_rcnt;
}

//------------------------------------------------------------------------------
/** @brief    uart 내부 수신버퍼에서 데이타를 읽어온다. 
    @param    obj  폴객체 포인터
    @param    buf  데이타를 담아올 버퍼
    @param    len  버퍼의 길이
    @return   복사된 데이타 길이
    @remark   데이타를 복사한 후 복사한 크기만큼 버퍼의 앞쪽으로 데이타를 이동한다.
*///----------------------------------------------------------------------------
int  uart_copy_recv_fifo( poll_obj_t *obj, char *buf, int len )
{
	uart_priv_t *uart;

	uart = (uart_priv_t *)obj->priv;  
	
	if ( len > uart->fifo_rcnt ) len = uart->fifo_rcnt;
	
	memcpy( buf, uart->recv_fifo, len );
	uart->fifo_rcnt -= len;
	
	if ( 0 < uart->fifo_rcnt )
	{
		memmove( uart->recv_fifo, uart->recv_fifo+len, uart->fifo_rcnt );
	}
	
	return len;
}
//------------------------------------------------------------------------------
/** @brief    uart 내부 수신버퍼의 포인터를 얻는다.
    @param    obj  폴객체 포인터
    @return   uart 내부 수신버퍼의 포인터
*///----------------------------------------------------------------------------
char *uart_get_recv_fifo( poll_obj_t *obj )
{
	uart_priv_t *uart;
	uart = (uart_priv_t *)obj->priv;  

	return uart->recv_fifo;
}
//------------------------------------------------------------------------------
/** @brief    uart 내부 수신버퍼에 저장된 데이타의 갯수를 얻는다.
    @param    obj  폴객체 포인터
    @return   수신버퍼에 저장된 데이타의 갯수
*///----------------------------------------------------------------------------
int  uart_get_recv_fifo_count( poll_obj_t *obj )
{
	uart_priv_t *uart;
	uart = (uart_priv_t *)obj->priv;  

	return uart->fifo_rcnt;
}
//------------------------------------------------------------------------------
/** @brief    uart 내부 수신버퍼에서 앞쪽의 데이타를 제거한 후 뒤쪽의 데이타를 이동한다.
    @param    obj   폴객체 포인터
    @param    len   제거될 데이타 개수
    @return   수신버퍼에 남아있는 데이타의 갯수
*///----------------------------------------------------------------------------
int  uart_checkout_recv_fifo( poll_obj_t *obj, int len )
{
	uart_priv_t *uart;
	uart = (uart_priv_t *)obj->priv;  

	uart->fifo_rcnt -= len;
	if ( 0 > uart->fifo_rcnt ) uart->fifo_rcnt = 0;
	
	if ( 0 < uart->fifo_rcnt )
	{
		memmove( uart->recv_fifo, uart->recv_fifo+len, uart->fifo_rcnt );
	}
	
	return uart->fifo_rcnt;
}



