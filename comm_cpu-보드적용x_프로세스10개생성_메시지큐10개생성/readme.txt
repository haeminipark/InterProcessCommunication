It creates 10 processes (proc_test0~proc_test9) and 10 message queues (MsgQ_0~MsgQ9) in proc_main.
It creates a sending thread and a receiving thread in proc_test0~proc_test9.
The sending thread sends 20 bytes of data to MsgQ. (msgsnd)
The receiving thread receives 20 bytes of data from MsgQ. (msgrcv)

proc_main에 10개의 프로세스(proc_test0~proc_test9)와 10개의 메시지 큐(MsgQ_0~MsgQ9)를 생성한다.
proc_test0~proc_test9에 송신 스레드(tx_thread_function)와 수신 스레드(rx_thread_function)를 생성한다.
송신 스레드는 MsgQ에게 20바이트의 데이터를 보낸다. (msgsnd)
수신 스레드는 MsgQ에서 20바이트의 데이터를 받는다. (msgrcv)

프로그램 실행
./mk