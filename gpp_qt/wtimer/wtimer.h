#ifndef WTIMER
#define WTIMER

//�����������������趨ʱ��

class wtimer
{
public:
	double nowtic(){return _nowtic;};
	void settic(double nt){_nowtic =nt;};
private:
	double _nowtic;
};

#endif
