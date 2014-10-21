#ifndef DATAFEED
#define DATAFEED

/////////////////////////////////////////
//#include"../match_engine/match_engine.h"
#include<string>
#include<fstream>

#include<map>
#include<list>

/////////////////////////////////////////
//�ϲ������Ѿ�ʵ�֣������漰��string�ıȽ����⣬Ч�ʽϵ�
//�����Ծ��漰����׼���ݵı�ʾ��ʽ���⣬���׼����������ø���Ч�ķ�ʽ�����бȽ�



#define FILE_RECORD_BUFFER 10

//class match_engine; 
class datafeed
{
public:
	//void updatemessage(match_engine &);
	void setfile(const std::string & filename);//����cache�ļ�
	void run();//��ʼcache
	void checkfilecache();//��ʱ��˳��ϲ��ļ�cache 
	void reloadcache();//����cache�գ��򲹳�
	void sendmessage(const std::string & message);//����չ���м��
	void feedcache(const std::string & );//�����ļ�cache

	std::list<std::string> _filenames;//�ļ����б� һ���ļ���ȡ��� �ᱻ�ļ��б����
	std::map<long,std::string> _quotecache;//ϵͳ���õ�����cache ��map��ԭ����map�Զ�������

	std::map<std::string,std::list<std::string> > _filecache;//ÿ���ļ���cache ����ʱ��_quotecache��_filecache��û���߼���ͻ
	std::map<std::string,std::ifstream * > _filehandle;//ÿ���ļ���handle


//tiny part	
	std::map<std::string,std::map<long,std::string> > _tiny;
	void find_next();
	std::string _retstring;
	std::string _nowfile;
	long getsize();
	

private:

};

#endif

/*
�����n���ļ�
ԭ�� �趨������ֵ 
	ÿ�ζ���ĳ�ļ�queue���һ����¼ ����»��档������δ�ﵽ��ֵ�����ݣ����Ҹ��µ���Ϊ��Ϊ��ֵ��

ʱ��
	�״θ��»��档
	
	������Ҫ�ٴθ��»��档
	��������ļ��������

����
	��ȡqueue���ݲ����� fifo
	һ����queue���򷢲�����
	֪ͨ���»���
		
	����cache�е����ݲ��ز�© Ҳ����queue�е�˳�򼴱����ȫ���ݼ���Ҳ�ǳ��ŵģ��м䲻��������

	����ĳ����Ϊmatch_engine��Ա Ŀǰ��ô�� �и��õĻ���ô��
*/

