#include<map>
#include<iostream>
#include<fstream>
#include<stdlib.h>

#include"./option/vnoption.h"
#include"./option/vnsnapshot.h"
#include"./option/spread_error_check.h"

#include"./cfg/cfg.h"
#include"./wtimer/wtimer.h"
#include"./wfunction/wfunction.h"

#include"./log_info/log_info.h"

#include"./future/futurerecord.h"
#include"./future/futuresnapshot.h"

#include"./bar/bar.h"
#include"./datafeed/datafeed.h"
#include"./trans_event/trans_event.h"
#include"./fillpolicy/fillpolicy.h"

#include"./match_engine/match_engine.h"
#include"./match_engine/order.h"
#include"./match_engine/orderlist.h"
#include"./match_engine/orderbook.h"

//g++ main.cpp  ./cfg/cfg.cpp ./wtimer/wtimer.cpp ./wfunction/wfunction.cpp ./log_info/log_info.cpp  ./datafeed/datafeed.cpp ./trans_event/trans_event.cpp  ./fillpolicy/fillpolicy.cpp  ./match_engine/order.cpp ./match_engine/orderlist.cpp ./match_engine/orderbook.cpp ./match_engine/match_engine.cpp  
//20140723 g++ ����������   vs����� ���г��� ʧЧ�ĵ�����
//20140723 ������������ �������match_engine.cpp��47�У�find�� ԭ���ǵ�ʱ_nowsymbol ��δ����㿪ʼ���ң����ص�end��������g++��end�������������� ==end ���ж�Ӧ��second


//dll������δ�㶨 ����дtacticʱ��Ҫ�ѽ����ĺ�������class����  class�зŷǽ�������
using namespace std;

cfg simucfg;		//������Ϣ
wtimer tm;			//ʱ���
log_info loginfo;	//��¼log
match_engine me;	//���ϵͳ
datafeed df;		//����Դ
trans_event te;		//��Ϣ������

int main()
{
	simucfg.loadfile();
	string quotefiles=	simucfg.getparam("datafeedfile");
	string fpname	=	simucfg.getparam("fillpolicy");

	me.loadfillpolicy(fpname);
	df.setfile(quotefiles);

	df.run();
}
/*
int main()
{
	
	//����option�������� ע����vnsnapshot�е�һ��
	string InstrumentID;//eg IO1401
	string callput;		//eg C
	long tm;			//eg 
	double StrikePrice;	//eg 2350
	double BidPrice1;	//eg 20
	double AskPrice1;	//eg 25
	double BidSize1;	//eg 20
	double AskSize1;	//eg 25
	
	
	ifstream infile;
	string filename="C:\\Users\\dell\\Desktop\\testlogic.txt";
	infile.open(filename.c_str());
	if(! infile.is_open()) //����ļ�������
	{
		cerr << "Cannot openfile " << filename.c_str() << endl;
		getchar();
		return 1;
	}
	string tp;
	while(getline(infile,tp))
	{
		int count=0;
		while(tp.size())
		{		
			static int index=0;
			count++;
			index=tp.find_first_of("\t");

			string tmpstring=tp.substr(0,index);
			switch(count)
			{
				case 1:InstrumentID	=tmpstring;					break;
				case 2:callput		=tmpstring;					break;
				case 3:tm			=atol(tmpstring.c_str());	break;
				case 4:StrikePrice	=atof(tmpstring.c_str());	break;
				case 5:BidPrice1	=atof(tmpstring.c_str());	break;
				case 6:AskPrice1	=atof(tmpstring.c_str());	break;
				case 7:BidSize1		=atof(tmpstring.c_str());	break;
				case 8:AskSize1		=atof(tp.c_str());			break;
			}
			if(index==-1)
			{
				break;
			}
			tp=tp.substr(index+1);

		}
	//	vo.updaterecord(InstrumentID, callput , tm, StrikePrice, BidPrice1 , AskPrice1, BidSize1 , AskSize1);
	//	sec.eachfunction(vo);
	//	cout<<" "<<tm<<" "<<StrikePrice<<" "<<BidPrice1<<" "<<AskPrice1<<endl;
	}
	//getchar();
	return 0;
}

*/
/*
���ڼ���ģ���ֿ���ctp������
1.		ctp�൱��ģ���е�datafeed fp 
2.		ģ�����Ƿ���Ҫʵ���жϵķ�ʽ�����ʵ��or��β�ʵ�����ܽ���ģ�� �ǲ����漰���������⣬ ��д��ģ����� Ȼ����ctp����Ӧ���������ģ����򣿻�֮  Ч�ʻ᲻�������
3.		��Ҫ��װ�ӿ�		
*/

