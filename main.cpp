#include"mainwindow.h"
#include<QApplication>

#include<stdio.h>
#include<stdlib.h> 
#include<Windows.h>

#include"gpp_qt/cfg/cfg.h"
#include"gpp_qt/bar/bars.h"
#include"gpp_qt/wtimer/wtimer.h"

#include"ctp_quote.h"

#include"ctp/ThostFtdcMdApi.h"
#include"ctp/ThostFtdcTraderApi.h"

using namespace std;

cfg simucfg;
wtimer tm;
bars mybars;
CThostFtdcMdApi * pUserApi;




MainWindow * mw;
QApplication * qa;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    qa=&a;
    mw=&w;

	simucfg.setcfgfile("c:/cfg/simu_trade.cfg");
	ctp_quote quote;
	CThostFtdcMdApi * pUserApi;
	pUserApi=CThostFtdcMdApi::CreateFtdcMdApi();			// ´´½¨UserApi
	pUserApi->RegisterSpi(&quote);
	pUserApi->RegisterFront(const_cast<char*>(simucfg.getparam("FRONT_ADDR").c_str()));
	pUserApi->Init();
	pUserApi->Join();
	w.show();
	
    return a.exec();
//	return 0;
}
