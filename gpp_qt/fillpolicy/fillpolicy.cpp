#include"fillpolicy.h"
#include"../match_engine/match_engine.h"
#include"../wtimer/wtimer.h"
#include"../trans_event/trans_event.h"


//extern wtimer tm;

extern trans_event te;
using namespace std;
//updateorderlistʱ����Ϣ����ĳ��������ȫ��order����� ������Ϣ
//����tactic��˵ �����̵õ�fp����Ϣ������
//tactic �ȵõ�fp����Ϣ ��õ�quote����Ϣ �ڽ������ݵ�����������ȷ�� ��ʵʱ������ҲӦ����ȷ��

//next add te part

void fillpolicy::updateorderlist(orderlist & ol,orderbook & ob)
{
	//��Ϣfill					���run������Щorder�ɳɽ� �ɽ�֮ 
	//ת��fill					���ɽ���ɵ�����done list
	//��Ϣchange ack rej done	���run done������list�е�change tag ������֮
	//ת��						��pend��ת����run��
	
	//��Ϣfill
	//ת��fill
	for(map<string,order *>::iterator iter=ol._run_order.begin(); iter!=ol._run_order.end();)
	{
		if((iter->second->_price>=ob.getaskprice() && iter->second->_buysell=="buy") || (iter->second->_price<=ob.getbidprice() &&iter->second->_buysell=="buy"))
		{
			iter->second->orderfill(iter->second->_sizetofill);
			ol._done_order[iter->first]=iter->second;
			ol._run_order.erase(iter++);
			//pme->fp_te_tactic_fill("");
		}
		else
		{
			++iter;
		}
	}
	
	//��Ϣchange
	//�ɹ�����
	for(map<string,order *>::iterator iter=ol._run_order.begin(); iter!=ol._run_order.end();)
	{
		if(iter->second->_tag_cancel)
		{
			iter->second->changeack("cancel");
			ol._done_order[iter->first]=iter->second;
			iter->second->changedone("cancel");
			ol._run_order.erase(iter++);
			continue;
		}
		else
		{
			++iter;
			continue;
		}
		if(iter->second->_tag_changeprice)
		{
			iter->second->changeack("price");
			iter->second->_price=iter->second->_tag_changeprice;
			iter->second->changedone("price");
		}
		if(iter->second->_tag_changesize)
		{
			
			iter->second->changeack("size");
			iter->second->_price=iter->second->_tag_changesize;
			iter->second->changedone("size");
		}
		++iter;
	}
	//ʧ�ܲ���
	for(map<string,order *>::iterator iter=ol._done_order.begin();iter!=ol._done_order.end();iter++)
	{
		if(iter->second->_tag_cancel)
		{
			iter->second->changeack("cancel");
			iter->second->changerej("cancel");
		}
		if(iter->second->_tag_changeprice)
		{
			iter->second->changeack("price");
			iter->second->changerej("price");
		}
		if(iter->second->_tag_changesize)
		{
			iter->second->changeack("size");
			iter->second->changerej("size");
		}
	}

	//ת��pend �����
	for(map<string,order *>::iterator iter=ol._pend_order.begin();iter!=ol._pend_order.end();iter++)
	{
		ol._run_order[iter->first]=iter->second;
	}
	ol._pend_order.clear();

	return;
}
	
