// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� TACTIC_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// TACTIC_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef TACTIC_EXPORTS
#define TACTIC_API __declspec(dllexport)
#else
#define TACTIC_API __declspec(dllimport)
#endif


#include<list>
#include<string>
#include "../../gpp_qt/trans_event/trans_event.h"


class torder;


// �����Ǵ� tactic.dll ������
class TACTIC_API tactic {
public:
	tactic(void);
	// TODO: �ڴ�������ķ�����	
	void init();
	void set_te(trans_event *);

	//quote���
	void add_quote_symbol(const std::string &);
	//��������Щsymbol��quote ����quote����
	void del_quote_symbol(const std::string &);
	//������Щsymbol��quote
	
	
	void readquote(const std::string & symbol, const std::string & ba, long level, double price, long size);
	const char * get_pending_message();
	
	
	//order���
	void add_order_symbol(const std::string &);
	void del_order_symbol(const std::string &);

	//fp to tactic info transfer
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
	//����
	void _delete_same_symbol(std::list<std::string> *);
	void _delete_symbol(std::list<std::string> *,const std::string & );
		
	std::list<std::string> _quote_symbols;
	std::list<std::string> _order_symbols;

	trans_event * _pte;
	std::list<torder *> _ol;
	std::string pending_message;

};
class torder
{
public:
	std::string orderid;
	std::string symbol;
	std::string buysell;
	double price;
	long size;
	
	long begtm;
	long endtm;
	long sizetofill;
	long sizefilled;
	long alreadyfilled;
	
	bool tag_cancel;
	long tag_changesize;
	double tag_changeprice;
};