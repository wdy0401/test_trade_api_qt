#ifndef SPREAD_ERROR_CHECK
#define SPREAD_ERROR_CHECK

#include"../wfunction/wfunction.h"
#include"vnoption.h"
#include<set>


class Spread_error_check
{
	public:
		void eachfunction(Vnoption);
	
	private:
		void _check_error(Vnoption);
		void _updatelist(Vnsnapshot);
		std::map<std::string,std::set<std::string> >	_eachoptiongroup; //��IO1401C�и���ִ�м۸�Ķ��ŵ�һ��group����
};

#endif

/*
1.����list
2.����ÿ��list�ļ۲���� ������۲��� �ݶ�Ϊstdout
*/