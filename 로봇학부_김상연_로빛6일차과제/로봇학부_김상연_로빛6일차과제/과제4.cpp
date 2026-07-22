#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//날짜 구조체
struct date {
	int year;
	int month;
	int day;
};
//시각 구조체
struct clock {
	int hour;
	int min;
	int sec;
};
//중첩 구조체 : 날짜 구조체 + 시각 구조체를 하나로 묶음
struct datetime {
	struct date d;
	struct clock t;
};
//2024년이 윤년이라 2월 계산 틀어짐 -> 윤년 체크 함수 추가함
int is_leap(int y) {
	return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}
//해당 월에 며칠 있는지 리턴 (윤년이면 2월 29일로)
int days_in_month(int y, int m) {
	int table[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (m == 2 && is_leap(y))
		return 29;
	return table[m - 1];
}
//기준일(1년 1월 1일)부터 해당 날짜까지 총 며칠인지 계산
long total_days(struct date d) {
	long days = 0;
	int y, m;
	//1년부터 입력받은 연도 직전까지 1년씩 다 더하기 (윤년이면 366일)
	for (y = 1;y < d.year;y++) {
		days += is_leap(y) ? 366 : 365;
	}
	//해당 연도의 1월부터 입력받은 달 직전까지 더하기
	for (m = 1;m < d.month;m++) {
		days += days_in_month(d.year, m);
	}
	days += d.day;
	return days;
}
//날짜+시각을 전부 초 단위로 환산
long get_total_sec(struct datetime dt) {
	long days = total_days(dt.d);
	long sec = dt.t.hour * 3600 + dt.t.min * 60 + dt.t.sec;
	return days * 86400 + sec;
}
int main() {
	struct datetime dt1, dt2;
	long total1, total2, diff;
	int hour, min, sec;
	printf("입력 : ");
	scanf_s("%d %d %d %d %d %d", &dt1.d.year, &dt1.d.month, &dt1.d.day,
		&dt1.t.hour, &dt1.t.min, &dt1.t.sec);
	scanf_s("%d %d %d %d %d %d", &dt2.d.year, &dt2.d.month, &dt2.d.day,
		&dt2.t.hour, &dt2.t.min, &dt2.t.sec);
	total1 = get_total_sec(dt1);
	total2 = get_total_sec(dt2);
	//두 시각 차이 (순서 상관없이 양수로)
	diff = (total2 > total1) ? total2 - total1 : total1 - total2;
	hour = diff / 3600;
	min = (diff % 3600) / 60;
	sec = diff % 60;
	printf("\n출력 : %d시 %d분 %d초\n", hour, min, sec);
	return 0;
}