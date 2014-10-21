#ifndef TRANS_EVENT
#define TRANS_EVENT

#include<iostream>
#include<fstream>
#include<string>
#include<map>

//������ME��datafeed֮�䴫����Ϣ  2014-07-03
//������ match_engine.cpp�� 2014-07-14
//����Ӧ�÷�ʽ����������� ��ͬrelease�汾���ܲ���֤һ��or������� ������Լ����౩¶
//����protobuffer ��д�˳��� 2014-08-06

class trans_event
{
public:
	trans_event();
	~trans_event();

	void setmessagefile(const std::string &);

	void datafeed_me(const std::string &);//����Ϣ
	void datafeed_me(const std::string & symbol, const std::string & ba, long level, double price, long size);//��׼bid ask ��Ϣ
	void datafeed_me(const std::string &,const std::map<std::string,std::string> &);//�Ǳ�׼��Ϣ
	
	//quote transfer
	void trans_quote(const std::string & symbol, const std::string & ba, long level, double price, long size);
	void fetch_tactic_info();
	//send order 
	void add_order(const std::string & symbol,  const std::string & buysell, double price ,long size);//add order
	
	//fp to tactic
	void order_send_ack(const std::string & orderid);
	void order_change_size_ack(const std::string & orderid, long size);
	void order_change_price_ack(const std::string & orderid, double price);

	void order_fill(const std::string & orderid,long fillsize);
	
	void order_change_size_rej(const std::string & orderid, long size);
	void order_change_price_rej(const std::string & orderid, double price);
	
	void order_change_size_done(const std::string & orderid, long size);
	void order_change_price_done(const std::string & orderid, double price);
	//end
private:
	bool _recordmessage;
	std::ifstream * _pfile;
};

#endif

