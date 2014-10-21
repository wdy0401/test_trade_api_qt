#include"stdafx.h"
#include"quote.pb.h"
#include<Windows.h>
#include<iostream>
#include<fstream>
#include<string>
#include<list>
#include<stdio.h>

#pragma comment(lib,"libprotobuf.lib")
#pragma comment(lib,"libprotoc.lib")

using namespace std;
using namespace QUOTE;

list<string> splitstring(std::string tp,std::string splitchar);

//璇诲彇plain text骞跺啓鍏rotobuffer鏍煎紡鏂囦欢銆�

int main(int argc, char * argv[])
{
	qrs msgs;
	
	fstream output("d:/proto_buffer.log",ios::out | ios::trunc | ios::binary); 
	
	string plaintxt_filename="d:/data_trans_IF1401_100.csv";
	if(argv[1])
	{
		//wstring a=argv[1];
		//string pf(a.begin(),a.end());
		plaintxt_filename=argv[1];
	}
	
	cout<<plaintxt_filename<<endl;
	//getchar();
	//return 0;

	fstream file_input(plaintxt_filename.c_str(), ios::in); 
	string tmpstring;
	long lines=0;
	while(getline(file_input,tmpstring))
	{
			
		list<string> lists=splitstring(tmpstring,",");
		list<string>::iterator iter=lists.begin();

		double	nowtime=atof(iter->c_str());
		string	symbol=(++iter)->c_str();
		string	bidask=(++iter)->c_str();
		long	level=atol((++iter)->c_str());
		double	price=atof((++iter)->c_str());
		long	size=atol((++iter)->c_str());
		bool	tradeable=atol((++iter)->c_str());

		msgs.set_symbol(symbol);

		quote_record* msg=new quote_record;
		msg->set_tm(nowtime);
		msg->set_type(bidask);
		msg->set_price(price);
		msg->set_size(size);
		msg->set_level(level);
		msg->set_tradeable(tradeable);
		
		msgs.add_qr()->MergeFrom(*msg);
		lines++;
		msgs.set_lines(lines);
	}
	if (!msgs.SerializeToOstream(&output))
	{ 
		cerr << "Failed to write msg." << endl; 
		return -1; 
	}
	output.close();
	file_input.close();

//	return 0;
	fstream input("d:/proto_buffer.log", ios::in | ios::binary); 
	msgs.Clear();
	
	qrs msgss;
	
	msgss.ParseFromIstream(&input);

	google::protobuf::int64 readlines= msgss.lines();
	//cout <<msgs.qr_size()<<"     "<<readlines<<endl;//杩欎釜size涓嶇煡閬撴槸骞蹭粈涔堢敤鐨� 
	return 0;
	for(int i=0;i<readlines;i++)
	{
		cout<<std::fixed<<msgss.mutable_qr()->Get(i).tm()<<endl;
		cout<<msgss.mutable_qr()->Get(i).size()<<endl;
	}
	
//	getchar();
	int i=1;
	return 0;
}

list<string> splitstring(std::string tp,std::string splitchar)
{
	list<string> ret;
	while(tp.size())
	{		
		static int index=0;
		index=tp.find_first_of(splitchar);

		string tmpstring=tp.substr(0,index);
		ret.push_back(tmpstring);

		if(index==-1)
		{
			break;
		}
		tp=tp.substr(index+1);
	}
	return ret;
}
