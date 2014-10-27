#ifndef CTP_QUOTE
#define CTP_QUOTE

#include"ctp/ThostFtdcMdApi.h"

class ctp_quote : public CThostFtdcMdSpi
{
public:
	ctp_quote();
	//void login();
	void ReqUserLogin();
	void OnRspError(CThostFtdcRspInfoField *pRspInfo,int nRequestID, bool bIsLast);

	///        0x2003 �յ�������
	void OnFrontDisconnected(int nReason);

	///���ͻ����뽻�׺�̨������ͨ������ʱ����δ��¼ǰ�����÷��������á�
	void OnFrontConnected();
	
	///��¼������Ӧ
	void OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin,	CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///��������Ӧ��
	void OnRspSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///ȡ����������Ӧ��
	void OnRspUnSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�������֪ͨ
	void OnRtnDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData);

	void SubscribeMarketData();
	bool IsErrorRspInfo(CThostFtdcRspInfoField *pRspInfo);
	
private:
//	CThostFtdcMdApi * pUserApi;
	CThostFtdcReqUserLoginField * req;
	int nRequestID;
	char ** ppInstrumentID;
	int nppInstrumentID;
};

#endif