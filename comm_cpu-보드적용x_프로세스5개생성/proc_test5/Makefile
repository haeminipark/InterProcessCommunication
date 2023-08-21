#
# falinux 라이블러리를 사용하는 어플용 Makefile
#

#CROSS_PREFIX	= mipsel-linux
#CROSS_PREFIX	= arm-linux
CROSS_PREFIX = #/opt/railway/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu
#CROSS_VERSION   = 3.4.4

CP_DIR          = ../image/
TOP_DIR         = ../

## 사용자 소스
TARGET			= PROC_TEST5
SRCS			= proc_test5.c


#---------------------------------------------------------------------
## 소스레벨의 라이브러리
DIR_COMMON      = #$(TOP_DIR)common/

SRCS_COMMON		= #$(DIR_COMMON)comLib.c 
SRCS_FANET		= 
SRCS            += $(SRCS_COMMON)

## 인클루드 디렉토리
INCLUDEDIRS		+= -I. -I$(TOP_DIR)include
## 내 PC 에서 컴파일 할때 참조해야할 스텐다드 라이브러리 경로(-L/usr/arm-linux/lib)를 추가.. , pthread 문을 사용하기 위해서
LIVDIRS			+= #-L$(TOP_DIR)lib/$(CROSS_PREFIX)$(CROSS_VERSION)lib -L/usr/arm-linux/lib

OBJS			= $(SRCS:.c=.o)

CFLAGS			= $(INCLUDEDIRS) -W  -O2 
LDFLAGS			= $(LIVDIRS)
LIBS			= -lm -lpthread

#---------------------------------------------------------------------
CC				=	$(CROSS_PREFIX)-gcc
CXX			 	=	$(CROSS_PREFIX)-g++
AR				=	$(CROSS_PREFIX)-ar rc
AR2				=	$(CROSS_PREFIX)-ranlib
RANLIB			=	$(CROSS_PREFIX)-ranlib
LD				=	$(CROSS_PREFIX)-ld
NM				=	$(CROSS_PREFIX)-nm
STRIP			=	$(CROSS_PREFIX)-strip
OBJCOPY		 	=	$(CROSS_PREFIX)-objcopy
CP	= cp
MV	= mv
#--------------------------------------------------------------------

all : $(TARGET)
	cp $^ $(CP_DIR).

$(TARGET) : $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $@ $(LIBS) 
	$(NM) $(TARGET) > $(TARGET).map

%.o:%.c
	@echo "Compiling $< ..."
	$(CC) -c $(CFLAGS) -o $@ $<

%.o:%.cc
	@echo "C++ compiling $< ..."
	$(CXX) -c $(CFLAGS) $(CXXFLAGS) -o $@ $<

dep :
	$(CC)	-M	$(INCLUDEDIRS)	$(SRCS) > .depend

clean:
	rm -f *.bak
	rm -f *.map
	rm -f *.o
	rm -f $(OBJS)
	rm -f $(TARGET) core

distclean: clean
	rm -rf .depend	


ifeq (.depend,$(wildcard .depend))
include .depend
endif



