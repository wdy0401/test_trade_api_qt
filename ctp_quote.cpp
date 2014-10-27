#include"ctp_quote.h"
#include"gpp_qt/cfg/cfg.h"
#include"gpp_qt/wfunction/wfunction.h"
#include<string>
#include<list>

#define MAX_CONTRACT_NUMBER 1024
#define MAX_CONTRACT_NAME 1024

extern cfg simucfg;
extern CThostFtdcMdApi * pUserApi;


using namespace std;
ctp_quote::ctp_quote()
{
	nRequestID=0;
	
	//char *ppInstrumentID[] = {"m1501","IF1411","IF1410","cu1501"};
	ppInstrumentID = new char*[MAX_CONTRACT_NUMBER];
	nppInstrumentID=0;
	list<string> contracts=wfunction::splitstring(simucfg.getparam("INSTRUMENT_ID"));
	for(list<string>::iterator iter=contracts.begin();iter!=contracts.end();iter++)
	{
		ppInstrumentID[nppInstrumentID]=new char [MAX_CONTRACT_NAME];
		ppInstrumentID[nppInstrumentID]=const_cast<char*>(iter->c_str());
		nppInstrumentID++;
	}

	string BROKER_ID=simucfg.getparam("BROKER_ID");
	string INVESTOR_ID=simucfg.getparam("INVESTOR_ID");
	string PASSWORD=simucfg.getparam("PASSWORD");

	req=new CThostFtdcReqUserLoginField;
	memset(req, 0, sizeof(*req));
	strncpy(req->BrokerID,const_cast<char*>(BROKER_ID.c_str()),sizeof(req->BrokerID));
	strncpy(req->UserID,const_cast<char*>(PASSWORD.c_str()),sizeof(req->UserID));
	strncpy(req->Password,const_cast<char*>(PASSWORD.c_str()),sizeof(req->Password));



/*		
	pUserApi=CThostFtdcMdApi::CreateFtdcMdApi();			// 创建UserApi
	pUserApi->RegisterSpi(this);
	pUserApi->RegisterFront(const_cast<char*>(simucfg.getparam("FRONT_ADDR").c_str()));
	pUserApi->Init();
	pUserApi->Join();
*/
}
/*
void ctp_quote::login()
{
	pUserApi=CThostFtdcMdApi::CreateFtdcMdApi();			// 创建UserApi
	pUserApi->RegisterSpi(this);
	pUserApi->RegisterFront(const_cast<char*>(simucfg.getparam("FRONT_ADDR").c_str()));
	pUserApi->Init();
	pUserApi->Join();
}
*/
void ctp_quote::ReqUserLogin()
{
	int iResult = pUserApi->ReqUserLogin(req, ++nRequestID);
	cout << "--->>> 发送用户登录请求: " << ((iResult == 0) ? "成功" : "失败") << endl;
}

void ctp_quote::OnRspError(CThostFtdcRspInfoField *pRspInfo,int nRequestID, bool bIsLast)
{
	//尚不清楚在具体哪种情况下会触发此回调
	cout<< "--->>> "<< "OnRspError\t RequeseID="<<nRequestID<< endl;
	IsErrorRspInfo(pRspInfo);
}
void ctp_quote::OnFrontDisconnected(int nReason)
{
	cout << "--->>> " << "OnFrontDisconnected" << endl;
	cout << "Reasons\n\t0x1001 网络读失败\n\t0x1002 网络写失败\n\t0x2001 接收心跳超时\n\t0x2002 发送心跳失败\n\t0x2003 收到错误报文"<<endl;
	cout << "\tReason = " << nReason << endl;
}

///当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
void ctp_quote::OnFrontConnected()
{
	cout << "--->>> " << "OnFrontConnected" << endl;
	ReqUserLogin();
}
	
///登录请求响应
void ctp_quote::OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin,	CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	cout << "--->>> " << "OnRspUserLogin" << endl;
	if (bIsLast && !IsErrorRspInfo(pRspInfo))
	{
		///获取当前交易日
		cout << "--->>> 获取当前交易日 = " << pUserApi->GetTradingDay()<< endl;
		// 请求订阅行情
		SubscribeMarketData();
	}
}
void ctp_quote::SubscribeMarketData()
{
	int iResult = pUserApi->SubscribeMarketData(ppInstrumentID, nppInstrumentID);
	cout << "--->>> 发送行情订阅请求: " << ((iResult == 0) ? "成功" : "失败") << endl;
}

///订阅行情应答
void ctp_quote::OnRspSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	cout << "OnRspSubMarketData" << endl;
}

///取消订阅行情应答
void ctp_quote::OnRspUnSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	cout << "OnRspUnSubMarketData" << endl;
}

///深度行情通知
void ctp_quote::OnRtnDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData)
{
	cout<< pDepthMarketData->TradingDay;
	cout<< "," << pDepthMarketData->UpdateTime;
	cout<< ":" << pDepthMarketData->UpdateMillisec;
	cout<< "," << pDepthMarketData->InstrumentID;
	cout<< "," << pDepthMarketData->BidPrice1;
	cout<< "," << pDepthMarketData->AskPrice1;
	cout<< "," << pDepthMarketData->BidVolume1;
	cout<< "," << pDepthMarketData->AskVolume1;
	cout<< "," << pDepthMarketData->LastPrice;
	cout<< "," << pDepthMarketData->HighestPrice;
	cout<< "," << pDepthMarketData->LowestPrice;
	cout<< "," << pDepthMarketData->Volume;
	cout<< endl;
}
bool ctp_quote::IsErrorRspInfo(CThostFtdcRspInfoField *pRspInfo)
{
	bool bResult = ((pRspInfo) && (pRspInfo->ErrorID != 0));
	if (bResult)
		cout << "--->>> ErrorID=" << pRspInfo->ErrorID << ", ErrorMsg=" << pRspInfo->ErrorMsg << endl;
	return bResult;
}
