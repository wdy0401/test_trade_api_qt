#ifndef VNOPTION
#define VNOPTION

#include<map>
#include<list>
#include"vnsnapshot.h"


//												main
//VNOPTION ��							IO												HO
//VNOPTION ����map��	IO1401	IO1402	IO1403				HO1401	HO1402	HO1403
//VNSNAPSHOT �� 			vnsnapshot	


//����Vnsnapshot ÿ��vnoptionʵ������һ��option��IO��IO1401����ȫ������
//ÿ����Լ��IO1401����Ӧһ��list��һ��snapshot
//list��snapshot�ֱ𱣴�������map�� _optionqueue _optionsnapshot
//_optionqueue�д����ÿ����Լ����ʷ��Ϣ����ʽΪlist�������趨list����
//_optionsnapshot �д����ÿ����Լ������snapshot



class Vnoption
{
public:

	void updaterecord(std::string InstrumentID, std::string callput, long tm, double StrikePrice, double BidPrice1 ,double AskPrice1, double BidSize1 ,double AskSize1);
	void set_maxqueuelength(unsigned int);
	std::map<std::string,Vnsnapshot> get_optionsnapshot();
	Vnsnapshot  get_lastsnapshot();
	Vnsnapshot  get_lastsnapshot(std::string);


private:

	std::map<std::string,std::list<Vnsnapshot> >	_optionqueue;
	std::map<std::string,Vnsnapshot>				_optionsnapshot;
	Vnsnapshot										_lastsnapshot;
	unsigned int									_maxqueuelength;

};
#endif