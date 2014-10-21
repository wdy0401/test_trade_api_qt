#ifndef ORDER
#define ORDER

#include<string>
#include<map>
#include<set>
//��Ҫ����
//����order�����ϲ���


class orderlist;

class order
{

friend class orderlist;
friend class fillpolicy;

public:
		
	//tactic����
	void initorder(const std::string &, const std::string &, double, long); //IF buy 2200 3 //ordid and timer will be added later
	void cancelorder();
	void changesize(long);
	void changeprice(double);

	//ME����
	//void setorderid(long); //MEά��ʱ���� ��ά��orderlist;

	//fp����
	void setorderid(long);
	void orderfill(long);
	void changerej(const std::string &);
	void changedone(const std::string &);
	void changeack(const std::string &);
	
private:
	//order������Ϣ
	long _orderid;//orderlist������
	std::string _symbol;
	std::string _buysell;//buy sell btc//buy to cover stc//sell to cover
	double _price;
	long _size;
	double _tm;

	//order��̬��Ϣ
	std::string tmpinfo;
	long _queueposition;
	long _sizefilled;
	long _sizetofill;
	long _eventid;//ÿ���¼� �и�id ����

	//order����fill��Ϣ
	long _sizeoverfilled;
	long _sizelackfilled;
	
	//��¼order�Ƿ���ȫfill
	bool _alreadyfilled;

	//�޸����࣬�˴���Ŵ��޸ĵ�����
	bool _tag_cancel;
	long _tag_changesize;
	double _tag_changeprice;
	
	//��ǿ��չ�� ��¼�����¼�   �¼�����_ʱ��   ʱ������ص�
	std::map<std::string,std::set<std::string> >	_eachcharacter; //other information

};

#endif
