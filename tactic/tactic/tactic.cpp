// tactic.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "tactic.h"
#include "iostream"
#include "../../gpp_qt/trans_event/trans_event.h"

using namespace std;

tactic::tactic()
{
	cout<<"Only for test lib change"<<endl;
	return;
}
void tactic::set_te(trans_event * tpte)
{
	_pte=tpte;
}
const char * tactic::get_pending_message()
{
	const char * ret=pending_message.c_str();
	pending_message.clear();
	return ret;
}
	
void tactic::readquote(const std::string & symbol, const std::string & ba, long level, double price, long size)
{
	cout << "TACTIC OUT : QUOTE READ "<<symbol<<" "<<ba<<" "<<level<<" "<<price<<" "<<size<<endl;
	//����Ҫ��orderд��pending_message��
	//�漰�� ��ΰѷ��ص�orderid�ŵ�order�е����� Ҳ����torder �� orderid���ƥ��
}

void tactic::add_quote_symbol(const string & symbol)
{
	string s=symbol;
	_quote_symbols.push_front(s);
	_delete_same_symbol(&_quote_symbols);
	return;
}

void tactic::del_quote_symbol(const string & symbol)
{
	_delete_symbol(&_quote_symbols,symbol);
	return;
}

void tactic::add_order_symbol(const string & symbol)
{
	string s=symbol;
	_order_symbols.push_front(s);
	_delete_same_symbol(&_order_symbols);
	return;
}
void tactic::del_order_symbol(const string & symbol)
{
	_delete_symbol(&_quote_symbols,symbol);
	return;
}
void tactic::_delete_same_symbol(list<string> * dlist)
{
	if(dlist->size()==0 || dlist->size()==1)
	{
		return;
	}
	for(list<string>::iterator iter=dlist->begin();;)
	{
		iter++;
		if(iter==dlist->end())
		{
			return;
		}
		if(dlist->begin()->c_str()==iter->c_str())
		{
			dlist->pop_front();
			return;
		}
	}
}
void tactic::_delete_symbol(list<string> * dlist,const string & symbol)
{
	if(dlist->size()==0 || dlist->size()==1)
	{
		return;
	}
	for(list<string>::iterator iter=dlist->begin();iter!=dlist->end();)
	{
		if(iter->c_str()==symbol.c_str())
		{
			dlist->erase(iter++);
		}
		else
		{
			++iter;
		}
	}
}
void tactic::order_send_ack(const std::string & orderid)
{
	cout<<"function name"<<endl;
	cout<<"    "<<"order_send_ack"<<endl;
	cout <<orderid<<"    "<<endl;
}
void tactic::order_change_size_ack(const std::string & orderid, long size)
{
	cout<<"function name"<<endl;
	cout<<"    "<<"order_change_size_ack"<<endl;
	cout <<orderid<<"    "<<size<<endl;
}
void tactic::order_change_price_ack(const std::string & orderid, double price)
{
	cout<<"function name"<<endl;
	cout<<"    "<<"order_change_price_ack"<<endl;
	cout <<orderid<<"    "<<price<<endl;
}
void tactic::order_fill(const std::string & orderid,long fillsize)
{
	cout<<"function name"<<endl;
	cout<<"    "<<"order_fill"<<endl;
	cout <<orderid<<"    "<<fillsize<<endl;
}
void tactic::order_change_size_rej(const std::string & orderid, long size)
{
	cout<<"function name"<<endl;
	cout<<"    "<<"order_change_size_rej"<<endl;
	cout <<orderid<<"    "<<size<<endl;
}
void tactic::order_change_price_rej(const std::string & orderid, double price)
{
	cout<<"function name"<<endl;
	cout<<"    "<<"order_change_price_rej"<<endl;
	cout <<orderid<<"    "<<price<<endl;
}
void tactic::order_change_size_done(const std::string & orderid, long size)
{
	cout<<"function name"<<endl;
	cout<<"    "<<"order_change_size_done"<<endl;
	cout <<orderid<<"    "<<size<<endl;
}
void tactic::order_change_price_done(const std::string & orderid, double price)
{
	cout<<"function name"<<endl;
	cout<<"    "<<"order_change_price_done"<<endl;
	cout <<orderid<<"    "<<price<<endl;
}


