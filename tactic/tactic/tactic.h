// 下列 ifdef 块是创建使从 DLL 导出更简单的
// 宏的标准方法。此 DLL 中的所有文件都是用命令行上定义的 TACTIC_EXPORTS
// 符号编译的。在使用此 DLL 的
// 任何其他项目上不应定义此符号。这样，源文件中包含此文件的任何其他项目都会将
// TACTIC_API 函数视为是从 DLL 导入的，而此 DLL 则将用此宏定义的
// 符号视为是被导出的。
#ifdef TACTIC_EXPORTS
#define TACTIC_API __declspec(dllexport)
#else
#define TACTIC_API __declspec(dllimport)
#endif


#include<list>
#include<string>
#include "../../gpp_qt/trans_event/trans_event.h"


class torder;


// 此类是从 tactic.dll 导出的
class TACTIC_API tactic {
public:
	tactic(void);
	// TODO: 在此添加您的方法。	
	void init();
	void set_te(trans_event *);

	//quote相关
	void add_quote_symbol(const std::string &);
	//接收收这些symbol的quote 其余quote不接
	void del_quote_symbol(const std::string &);
	//屏蔽这些symbol的quote
	
	
	void readquote(const std::string & symbol, const std::string & ba, long level, double price, long size);
	const char * get_pending_message();
	
	
	//order相关
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
	//工具
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