#-------------------------------------------------
#
# Project created by QtCreator 2014-08-14T17:05:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = exchange
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp\
     gpp_qt/bar/bar.cpp\
     gpp_qt/cfg/cfg.cpp\
     gpp_qt/datafeed/datafeed.cpp\
     gpp_qt/fillpolicy/fillpolicy.cpp\
     gpp_qt/log_info/log_info.cpp\
     gpp_qt/match_engine/match_engine.cpp\
     gpp_qt/match_engine/order.cpp\
     gpp_qt/match_engine/orderlist.cpp\
     gpp_qt/match_engine/orderbook.cpp\
     gpp_qt/option/vnoption.cpp\
     gpp_qt/option/vnsnapshot.cpp\
     gpp_qt/trans_event/trans_event.cpp\
     gpp_qt/wfunction/wfunction.cpp\
     gpp_qt/wtimer/wtimer.cpp \
     test_function.cpp \


HEADERS  += mainwindow.h \
     gpp_qt/bar/bar.h\
     gpp_qt/cfg/cfg.h\
     gpp_qt/datafeed/datafeed.h\
     gpp_qt/fillpolicy/fillpolicy.h\
     gpp_qt/log_info/log_info.h\
     gpp_qt/match_engine/match_engine.h\
     gpp_qt/match_engine/order.h\
     gpp_qt/match_engine/orderlist.h\
     gpp_qt/match_engine/orderbook.h\
     gpp_qt/option/vnoption.h\
     gpp_qt/option/vnsnapshot.h\
     gpp_qt/trans_event/trans_event.h\
     gpp_qt/wfunction/wfunction.h\
     gpp_qt/wtimer/wtimer.h \
    test_function.h \


FORMS    += mainwindow.ui
