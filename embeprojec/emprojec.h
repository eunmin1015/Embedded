#ifndef _emprojec_drv_
#define _emprojec_drv_


int setInit(void); //프로그램을 시작할때 각 기기의 초기설정을 해주고 온도값을 읽어와서 그에 따른 컨디션
int baseballgame(void);
int setExit(void); //열어놨던 각종 기기들과 txt 파일을 close 해준다.


#endif
