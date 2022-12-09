#ifndef _embe_drv_
#define _embe_drv_

typedef struct{
	int year;
	int month;
	int day;
	int hour;
	int min ;
	int sec ;
} hourAndMinute; //카운트 업과 카운트 다운에 필요한 시간과 날짜를 저장해주기 위해서 만든 구조체

int select_ball_func (void);
int soccergame(void);
int baseballgame(void);
int setInit(void);
int setExit(void);

#endif