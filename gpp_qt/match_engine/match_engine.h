#ifndef MATCH_ENGINE
#define MATCH_ENGINE

#include<string>
#include<map>
#include"orderbook.h"
#include"orderlist.h"
#include"order.h"
#include"../wtimer/wtimer.h"
#include"../fillpolicy/fillpolicy.h"
#include"../datafeed/datafeed.h"
#include"../../protobuf/order.pb.h"

//tactic
//���躯��
//0.��ʼ��
//1.�ջر�
//2.������
//3.���� �ĵ� ����


//��Ҫ����
//ģ�⽻�������д�Ͻ��ף����������ɴ����symbol�Ľ��ס�
//�����沢������ʵ��ʱ�䣬���ٶ�ȡ������Ϣ���ٶȡ����Ը���ĸ���ģ������
//�����������leg��Ϣ��������Ĵ���


//���ڶ���Ժϳɵĸ����ԣ���ME���������ԵĹ�ϵ�������������װ��ͬ���ӿ�

//ʱ���ϵΪ
//����orderbook(�������ã����ü��� ȡ��������Դ)
//�鿴fillpolicy��˳�����fill load��order ����ack or rej��
//����tactic����������orderlist��

//��Ϣ����ͨ��trans_event����


class match_engine
{
public:
	
	match_engine();

	bool loadtactic(std::string &);
	bool loadfillpolicy(std::string &);

	void rec_update(const std::string & symbol, const std::string & ba, long level, double price, long size);

	void setnowsymbol(const std::string & symbol);
	void updateorderbook(const std::string &,const std::string &,long,double,long);//IF1405 bid 1 2100.2 5
	void updatefp();//��дorderlist����order��״̬
	void updatetactic(const std::string & symbol, const std::string & ba, long level, double price, long size);//���µ�orderbook���ж�ʱ����order
	void updatetacticbooks();//�ڲ�����Ҫ�����bookʱʹ�� ��δʵ��
		
	void add_order(const std::string & symbol,  const std::string & buysell, double price ,long size);
	void add_order(const std::string & msg);

//�ⲿ����fp͸��me���͸�te����Ϣ
	
	void fp_te_tactic_order_send_ack(const std::string & orderid);
	void fp_te_tactic_order_change_size_ack(const std::string & orderid, long size);
	void fp_te_tactic_order_change_price_ack(const std::string & orderid, double price);

	void fp_te_tactic_order_fill(const std::string & orderid,long fillsize);
	
	void fp_te_tactic_order_change_size_rej(const std::string & orderid, long size);
	void fp_te_tactic_order_change_price_rej(const std::string & orderid, double price);
	
	void fp_te_tactic_order_change_size_done(const std::string & orderid, long size);
	void fp_te_tactic_order_change_price_done(const std::string & orderid, double price);
//end

private:
    std::map<std::string,orderbook> _orderbooks;
	fillpolicy _fp;
	orderlist _ol;
	std::string _nowsymbol;
	TRANS_ORDER::order _order_message;
};
#endif
