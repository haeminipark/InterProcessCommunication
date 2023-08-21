/**    
    @file     uart.c
    @date     2009-03-19
    @author   ����� freefrug@falinux.com
    @brief    uart �� ����� ����� ����Ѵ�.

    @modify   
    @todo    
    @bug     
    @remark   
    
    @warning 
*/
//
//  ���۱�    �������̸�����(��)
//            �ܺΰ��� ����
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


/// uart ���� ����ü
typedef struct {

	// ���۰���
	char  recv_fifo[UART_RECV_FIFO_MAX];	
	int   fifo_rcnt;

	char  port[256];
	
} uart_priv_t;


//------------------------------------------------------------------------------
/** @brief    uart �� open �Ѵ�.
    @param    fname  ���ڿ� �����̸�
    @return   poll_obj_t ������ ������
*///----------------------------------------------------------------------------
poll_obj_t  *uart_open( char *dev_name, int baud, char parity )
{
	int	fd;
	poll_obj_t  *obj;
	uart_priv_t *uart;
	struct termios  newtio;

	// �ø�����Ʈ�� ����.	
	fd = open( dev_name, O_RDWR | O_NOCTTY );
	if ( fd < 0 ) 
	{
		// ȭ�� ���� ����
		printf( "device open fail %s : ", dev_name );
		perror("");
		return NULL;
	}
    	
	// �ø��� ��Ʈ ȯ���� �����Ѵ�.
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
	switch( parity | 0x20 ) // �ҹ��� ó��
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
	    
	// uart ���� ������ �����Ѵ�.
	uart = (uart_priv_t *)malloc( sizeof(uart_priv_t) );
	memset( (void *)uart, 0, sizeof(uart_priv_t) );
	strcpy( uart->port, dev_name );

	obj = poll_add( fd );
	obj->type = STYP_UART;
	obj->priv = (void *)uart;
	
	return obj;
}
//------------------------------------------------------------------------------
/** @brief    uart �� close �Ѵ�.
    @param    obj  ����ü ������
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
/** @brief    uart ����ü�� �����̸����� ã�´�.
    @param    fname ���ڿ� �����̸�
    @return   obj  ����ü ������
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
/** @brief    uart �� ���� ����Ÿ�� �����Ѵ�.
    @param    obj  ����ü ������
    @param    buf  ���۹���
    @param    len  ������ ����
    @return   ������ ����Ÿ ����
*///----------------------------------------------------------------------------
int  uart_write( poll_obj_t *obj, char *buf, int len )
{
	int  wrcnt;
	
	// �����Ѵ�.
	wrcnt = write( obj->fd, buf, len );

	if ( 0 > wrcnt )
	{
		perror( "uart send error:" );	
	}
	
	return wrcnt;
}
//------------------------------------------------------------------------------
/** @brief    uart �� ���� ����Ÿ�� �д´�.
    @param    obj  ����ü ������
    @param    buf  �ϱ����
    @param    len  ������ ����
    @return   ���� ����Ÿ ����
*///----------------------------------------------------------------------------
int  uart_read( poll_obj_t *obj, char *buf, int len )
{
	int  rdcnt;

	// ����Ÿ�� �д´�.
	rdcnt = read( obj->fd, buf, len );
	
	if ( 0 > rdcnt )
	{
		perror( "uart recv error:" );
	}
	
	return rdcnt;
}
//------------------------------------------------------------------------------
/** @brief    uart ���� ���Ź��ۿ� ����Ÿ�� �����Ѵ�.
    @param    obj  ����ü ������
    @return   ���μ��Ź����� �� ����Ÿ ����
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
/** @brief    uart ���� ���Ź��ۿ��� ����Ÿ�� �о�´�. 
    @param    obj  ����ü ������
    @param    buf  ����Ÿ�� ��ƿ� ����
    @param    len  ������ ����
    @return   ����� ����Ÿ ����
    @remark   ����Ÿ�� ������ �� ������ ũ�⸸ŭ ������ �������� ����Ÿ�� �̵��Ѵ�.
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
/** @brief    uart ���� ���Ź����� �����͸� ��´�.
    @param    obj  ����ü ������
    @return   uart ���� ���Ź����� ������
*///----------------------------------------------------------------------------
char *uart_get_recv_fifo( poll_obj_t *obj )
{
	uart_priv_t *uart;
	uart = (uart_priv_t *)obj->priv;  

	return uart->recv_fifo;
}
//------------------------------------------------------------------------------
/** @brief    uart ���� ���Ź��ۿ� ����� ����Ÿ�� ������ ��´�.
    @param    obj  ����ü ������
    @return   ���Ź��ۿ� ����� ����Ÿ�� ����
*///----------------------------------------------------------------------------
int  uart_get_recv_fifo_count( poll_obj_t *obj )
{
	uart_priv_t *uart;
	uart = (uart_priv_t *)obj->priv;  

	return uart->fifo_rcnt;
}
//------------------------------------------------------------------------------
/** @brief    uart ���� ���Ź��ۿ��� ������ ����Ÿ�� ������ �� ������ ����Ÿ�� �̵��Ѵ�.
    @param    obj   ����ü ������
    @param    len   ���ŵ� ����Ÿ ����
    @return   ���Ź��ۿ� �����ִ� ����Ÿ�� ����
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



