#ifndef _MYDEFINE_H_
#define _MYDEFINE_H_

#define MSG_TEXT_MAX    20

typedef enum {

    MSGQ_0 = 0,
    MSGQ_1,
    MSGQ_2,
    MSGQ_3,   
    MSGQ_4, 
    MSGQ_5, 
    MSGQ_6, 
    MSGQ_7, 
    MSGQ_8,
    MSGQ_9,
    MSGQ_MAX,
} MSGQ_INFO;

int MsgQId[MSGQ_MAX];

#endif