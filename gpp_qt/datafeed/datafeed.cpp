#include"datafeed.h"
#include"../wfunction/wfunction.h"
#include"../wtimer/wtimer.h"
#include"../trans_event/trans_event.h"
#include<fstream>
#include<iostream>
#include<assert.h>
#include<string>
#include<list>

//#include"../match_engine/match_engine.h"

extern wtimer tm;
extern trans_event te;
using namespace std;

void datafeed::run()
{
	reloadcache();
	while(_quotecache.size()>0)
	{
		for(map<long,std::string>::iterator iter=_quotecache.begin();  iter!=_quotecache.end();  iter++)
		{
			sendmessage(iter->second);
		}
		_quotecache.clear();//���cache �Ա�reload
		reloadcache();
	}
}
void datafeed::setfile(const std::string & filename)
{
	list<string> filelist=wfunction::splitstring(filename);
	for(list<string>::iterator iter=filelist.begin();iter!=filelist.end();iter++)
	{
		_filenames.push_back(iter->c_str());
	}
}

void datafeed::checkfilecache()//��ʼmergeʱ������Ƿ��п�cache������ɾ�����ļ���handle����Ӧcache
{
	for(std::map<std::string,std::list<string> >::iterator iter=_filecache.begin();iter!=_filecache.end();)
	{
		if(iter->second.size()==0)
		{
			delete _filehandle.find(iter->first)->second;
			_filehandle.erase(_filehandle.find(iter->first));
			_filecache.erase(iter++);
		}
		else
		{
			++iter;
		}
	}
}
void datafeed::sendmessage(const string & msg)
{
	cout<<msg<<endl;
	list<string> lists=wfunction::splitstring(msg);
	list<string>::iterator iter=lists.begin();

	double	nowtime=atof(iter->c_str());
	tm.settic(nowtime);
	string	symbol=(++iter)->c_str();
	string	bidask=(++iter)->c_str();
	long	level=atol((++iter)->c_str());
	double	price=atof((++iter)->c_str());
	long	size=atol((++iter)->c_str());
	te.datafeed_me(symbol,bidask,level,price,size);
}

void datafeed::reloadcache()
{
	if(_filenames.size()==0 && _filecache.begin()->second.size()==0)//ɨβ��
	{
		checkfilecache();
		return;
	}
	if(_filenames.size()!=0)
	{		
		for(std::list<std::string>::iterator itnamelist=_filenames.begin();  itnamelist!=_filenames.end(); )
		{
			if(_filecache[itnamelist->data()].size() < FILE_RECORD_BUFFER)
			{
				std::list<std::string>::iterator it=itnamelist;
				it++;
				feedcache(itnamelist->data());
				itnamelist=it;
			}
			else
			{
				++itnamelist;
			}
		}
	}
	checkfilecache();

	//�����ݷ���quotecache
	for(int i=0;i<FILE_RECORD_BUFFER;i++)
	{
		find_next();
		if(_retstring!="")
		{
			_quotecache[i]=_retstring;
		}
		else
		{
			break;
		}
	}
}
void datafeed::feedcache(const string & filename)
{
	std::map<std::string,std::ifstream *>::iterator it =_filehandle.find(filename);
	
	if(it==_filehandle.end())//��ʼ��������
	{
		ifstream * infile=new ifstream;
		infile->open(filename.c_str());
		if(! infile->is_open()) //����ļ�������
		{
			cerr << "Cannot openfile " << filename.c_str() << endl;
		}
		_filehandle[filename]=infile;
	}

	//�����ļ���
	string tmpstring;
	for(int i=1;i<=FILE_RECORD_BUFFER;i++)
	{
		int emptyline=1;//0 normal  1 empty line   2 file end   
		while(emptyline)
		{
			if(getline(*_filehandle[filename],tmpstring))
			{
				if(tmpstring!="")
				{				
					_filecache[filename].push_back(tmpstring.c_str());
					emptyline=0;
				}
				else
				{
					emptyline=1;
				}
			}
			else
			{
				emptyline=2;
				break;
			}
		}
		
		if(emptyline==2)
		{
			cerr<<"File "<<filename<<" loaded"<<endl;
			_filenames.remove(filename);
			break;
		}
	}
}

void datafeed::find_next()
{
	if(this->getsize()==0)
	{
		for(std::map<std::string,std::list<std::string> >::iterator iter=_filecache.begin();iter!=_filecache.end();iter++)
		{
			if(iter->second.size()==0)
			{
				_retstring="";
				continue;
			}
			_tiny[(iter->second.begin()->data()+iter->first)][0]=iter->first;
			_tiny[(iter->second.begin()->data()+iter->first)][1]=iter->second.begin()->data();
		
			//����ԭcache
			iter->second.pop_front();
		}
		if(getsize()==0)
		{
			_retstring="";
			return;
		}
	}

	_retstring= _tiny.begin()->second[1];
	_nowfile=_tiny.begin()->second[0];
	_tiny.erase(_tiny.begin());
	std::map<std::string,std::list<std::string> >::iterator iter=_filecache.find(_nowfile);
	if(iter->second.size()>=1)
	{
		//�ɸĽ�֮��
		//tiny���Ը�Ϊ_tiny[201400000][0]=2014000000000   float����Ӧ����
		//            _tiny[201400000][1]=2014000000000,IF1401,,,,,
		//��Ϊ������ʱ�Ŀ��ٷ�������֮��
		
		//�ȼ����µ�����
		_tiny[(iter->second.begin()->data()+iter->first)][0]=iter->first;
		_tiny[(iter->second.begin()->data()+iter->first)][1]=iter->second.begin()->data();
				
		//�ٰ�Ҫ����datafeed�����ݵ���
		iter->second.pop_front();
	}
	return;
}

long datafeed::getsize()
{
	return _tiny.size();
}
