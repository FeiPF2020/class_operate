#pragma once
/*��������ʱ����ӣ�����ʱ��ĵ�λ��Сʱ�ͷ���
* ʹ�ò�����+������
*/

#ifndef MYTIME0_H_
#define MYTIME0_h_

class Time
{
public:
	Time();
	Time(int h ,int m = 0);
	void AddMin(int m);
	void AddHr(int h);
	void Reset(int h = 0, int m = 0);
	//Time Sum(const Time &t) const;
	Time operator+(const Time& t) const;
	Time operator-(const Time& t) const;
	Time operator*(double num) const;

	void Show() const;




private:
	int hours;
	int minutes;

};





#endif // !MYTIME0_H_
