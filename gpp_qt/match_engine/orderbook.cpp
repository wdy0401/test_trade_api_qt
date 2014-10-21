#include"orderbook.h"
#include<string>
#include<vector>
//��Ҫ����
//ʵʱ����orderbook��һ��match_engineʹ��

//Ŀǰδʵ��full book��Ϣ
//�ӿ���Ԥ��

using namespace std;
orderbook::orderbook()
{
	_fillsize=0;
}
void orderbook::updateorderbook(const std::string &bidask, long level, double price, long size)
{
	//����nbbo
	if (level==1)
	{
		if (bidask=="bid")
		{
			_bidprice=price;
			_bidsize=size;
		}
		if (bidask=="ask")
		{
			_askprice=price;
			_asksize=size;
		}
	}
	//����book
	if(bidask=="bid")
	{
		_bidlevelprice[level]=price;
		_bidlevelsize[level]=size;
	}
	if(bidask=="ask")
	{
		_asklevelprice[level]=price;
		_asklevelsize[level]=size;
	}
	if(bidask=="fill")
	{
		_lastfillsize=_fillsize;
		_fillsize=size;
	}
}

void orderbook::setsymbol(const std::string &symbol)
{
	_symbol=symbol;
}

std::string orderbook::getsymbol()
{
	return _symbol;
}

double orderbook::getbidprice(long level)
{
	if (level<=MAXLEVEL && _bidlevelprice[level] != 0)
	{
		return _bidlevelprice[level];
	}
	return 0;	
}

double orderbook::getaskprice(long level)
{
	if (level<=MAXLEVEL && _asklevelprice[level] != 0)
	{
		return _asklevelprice[level];
	}
	return 0;
}

long orderbook::getbidsize(long level)
{
	if (level<=MAXLEVEL && _bidlevelsize[level] != 0)
	{
		return _bidlevelsize[level];
	}
	return 0;
}

long orderbook::getasksize(long level)
{
	if (level<=MAXLEVEL && _asklevelsize[level] != 0)
	{
		return _asklevelsize[level];
	}
	return 0;
}
long orderbook::getbidsize()
{
	return getbidsize(1);
}
long orderbook::getasksize()
{
	return getasksize(1);
}
double orderbook::getbidprice()
{
	return getbidprice(1);
}
double orderbook::getaskprice()
{
	return getaskprice(1);
}
long orderbook::getfillsize()
{
	return _fillsize;
}
