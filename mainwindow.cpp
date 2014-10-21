#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "./gpp_qt/datafeed/datafeed.h"
#include "./gpp_qt/wfunction/wfunction.h"

#include<iostream>

#include<QFile>
#include<QString>
#include<QMessageBox>
#include<QTextStream>
#include<qtextcodec.h>
extern QApplication * qa;
using namespace std;



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
