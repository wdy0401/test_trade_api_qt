#include<math.h>
#include"bar.h"
#include"bars.h"
#include"../wtimer/wtimer.h"

extern wtimer tm;

using namespace std;

bars::bars()
{
	
}
void bars::setlength(long length)
{
	_length=length;
}
void bars::updatebar(double value,long volume)
{
	updatebar(value);
	_nowbar->setvolume(volume);
}
void bars::updatebar(double value)
{
	long nowseq=int(tm.nowtic()/_length);
	map<long,bar *>::iterator iter =_barmap.find(nowseq);
	if(iter != _barmap.end())
	{
		iter->second->setvalue(value);
	}
	else
	{
		_nowbar = new bar;
		_nowbar->setvalue(value);
		_barmap[nowseq]=_nowbar;
	}
}
bar * bars::mergebar(long number)
{
	if(_barmap.size()==0)
	{
		return new bar;
	}
	if(_barmap.size()<number)
	{
		return mergebar(_barmap.size());
	}

	bar * newbar=new bar;
	for(map<long,bar *>::iterator iter = _barmap.begin();iter!=_barmap.end();iter++)
	{
		if(iter->second->getbegtime()==0)
		{
			continue;
		}
		long beginbarnumber=_barmap.size()-number;
		if(iter->first<=beginbarnumber)
		{
			continue;
		}
		newbar->setvalue(iter->second->getopen(),iter->second->getbegtime());
		newbar->setvalue(iter->second->gethigh(),iter->second->getbegtime());
		newbar->setvalue(iter->second->getlow(),iter->second->getendtime());
		newbar->setvalue(iter->second->getclose(),iter->second->getendtime());
		newbar->setvalue(iter->second->getvolume(),iter->second->getendtime());
	}
	return newbar;
}
