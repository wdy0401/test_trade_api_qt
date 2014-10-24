#ifndef CFG
#define CFG

#include<iostream>
#include<fstream>
#include<string>
#include<map>

//�ڲ�����������ʱ��������ݽṹ����ʱ ��Ҫ��xml������ 
//xml�д�ʵ�� boost����û�У�

class cfg
{
public:
	cfg();
	~cfg();
    const std::string getparam(const std::string &);
	void setcfgfile(const std::string &);
	void addcfgfile(const std::string &);
	void setsep(const std::string &);
	void clearcfg();
	void loadfile();
private:
	std::map<std::string,std::string> _kvpair;
	std::string _cfgfile;
	std::string _sep;
	std::ifstream * _pfile;
};

#endif

