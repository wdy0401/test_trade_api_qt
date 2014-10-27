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
	pUserApi=CThostFtdcMdApi::CreateFtdcMdApi();			// ����UserApi
	pUserApi->RegisterSpi(this);
	pUserApi->RegisterFront(const_cast<char*>(simucfg.getparam("FRONT_ADDR").c_str()));
	pUserApi->Init();
	pUserApi->Join();
*/
}
/*
void ctp_quote::login()
{
	pUserApi=CThostFtdcMdApi::CreateFtdcMdApi();			// ����UserApi
	pUserApi->RegisterSpi(this);
	pUserApi->RegisterFront(const_cast<char*>(simucfg.getparam("FRONT_ADDR").c_str()));
	pUserApi->Init();
	pUserApi->Join();
}
*/
void ctp_quote::ReqUserLogin()
{
	int iResult = pUserApi->ReqUserLogin(req, ++nRequestID);
	cout << "--->>> �����û���¼����: " << ((iResult == 0) ? "�ɹ�" : "ʧ��") << endl;
}

void ctp_quote::OnRspError(CThostFtdcRspInfoField *pRspInfo,int nRequestID, bool bIsLast)
{
	//�в�����ھ�����������»ᴥ���˻ص�
	cout<< "--->>> "<< "OnRspError\t RequeseID="<<nRequestID<< endl;
	IsErrorRspInfo(pRspInfo);
}
void ctp_quote::OnFrontDisconnected(int nReason)
{
	cout << "--->>> " << "OnFrontDisconnected" << endl;
	cout << "Reasons\n\t0x1001 �����ʧ��\n\t0x1002 ����дʧ��\n\t0x2001 ����������ʱ\n\t0x2002 ��������ʧ��\n\t0x2003 �յ�������"<<endl;
	cout << "\tReason = " << nReason << endl;
}

///���ͻ����뽻�׺�̨������ͨ������ʱ����δ��¼ǰ�����÷��������á�
void ctp_quote::OnFrontConnected()
{
	cout << "--->>> " << "OnFrontConnected" << endl;
	ReqUserLogin();
}
	
///��¼������Ӧ
void ctp_quote::OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin,	CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	cout << "--->>> " << "OnRspUserLogin" << endl;
	if (bIsLast && !IsErrorRspInfo(pRspInfo))
	{
		///��ȡ��ǰ������
		cout << "--->>> ��ȡ��ǰ������ = " << pUserApi->GetTradingDay()<< endl;
		// ����������
		SubscribeMarketData();
	}
}
void ctp_quote::SubscribeMarketData()
{
	int iResult = pUserApi->SubscribeMarketData(ppInstrumentID, nppInstrumentID);
	cout << "--->>> �������鶩������: " << ((iResult == 0) ? "�ɹ�" : "ʧ��") << endl;
}

///��������Ӧ��
void ctp_quote::OnRspSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	cout << "OnRspSubMarketData" << endl;
}

///ȡ����������Ӧ��
void ctp_quote::OnRspUnSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	cout << "OnRspUnSubMarketData" << endl;
}

///�������֪ͨ
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
