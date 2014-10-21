#include"mainwindow.h"
#include<QApplication>

#include<stdio.h>
#include<stdlib.h> 
#include<Windows.h>

#include"gpp_qt/cfg/cfg.h"

#include"ctp/ThostFtdcMdApi.h"
#include"ctp/ThostFtdcTraderApi.h"

using namespace std;


cfg simucfg;
MainWindow * mw;
QApplication * qa;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    qa=&a;
    mw=&w;

    w.show();
	
    return a.exec();
}
