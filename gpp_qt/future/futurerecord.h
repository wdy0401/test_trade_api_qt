#ifndef FUTURERECORD
#define FUTURERECORD

//ά������ ��Ӧ������map һ����snapshot һ������ʱ��or�������Ƶ�queue
//������map һ���Ƕ�Ӧ��һ��snapshot һ���Ƕ�Ӧ��snap��

#include<map>
#include<list>
#include"futuresnapshot.h"

class Futurerecord
{
public:

	void updaterecord(std::string InstrumentID,  long tm,  double BidPrice1 ,double AskPrice1, double BidSize1 ,double AskSize1);
	void set_maxqueuelength(unsigned int);
	std::map<std::string,Futuresnapshot> get_futuresnapshot();
	Futuresnapshot  get_lastsnapshot();


private:

	std::map<std::string,std::list<Futuresnapshot> >	_futurequeue;
	std::map<std::string,Futuresnapshot>				_futuresnapshot;
	Futuresnapshot										_lastsnapshot;
	unsigned int									_maxqueuelength;

};
#endif