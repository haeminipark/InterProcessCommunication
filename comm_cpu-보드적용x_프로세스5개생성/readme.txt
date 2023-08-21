proc_main에 5개의 프로세스(proc_test1~proc_test5)를 생성한다.
proc_test1~proc_test5에 송신 스레드(tx_thread_function)와 수신 스레드(rx_thread_function)를 생성한다.
각 스레드는 1초마다 실행된다.

프로그램 실행
./mk