#include "operator.h"
using namespace std;

class CGoods{
public:
	CGoods(long number=0,char *name="",double p=0.0){no = number;P_name = new char[strlen(name)+1];strcpy(P_name,name);price = p;++count;cout<<"Creating object function execute"<<endl;}//���캯��
	CGoods(const CGoods &a){no = a.no;P_name = new char[strlen(a.P_name)+1];strcpy(P_name,a.P_name);price = a.price;++count;cout<<"Copy object function executive"<<endl;}//�������캯��
	~CGoods(){--count;delete P_name;P_name = NULL;cout<<"Delete object function executive"<<endl;}//��������
	void printCGood()const{cout<<no<<"\t"<<P_name<<"\t"<<price<<endl;};//��ӡ���ݳ�Ա�ĺ���
	static int getCount(){return count;}//��ȡ��Ʒ��������
	friend char* getName(const CGoods &a);

	//����С�������
	bool operator<(const CGoods &a){
		if(price<a.price)
			return true;
		else
			return false;
	}

	//���ش��ڵ��������
	bool operator>=(const CGoods &a){
		if (price>=a.price)
			return true;
		else
			return false;
	}

private:
	long no;//��Ʒ��
	char *P_name;//��Ʒ��
	double price;//��Ʒ�۸�
	static int count;//��Ʒ����

};
char* getName(const CGoods &a){
	return a.P_name;
}
int CGoods::count = 0;


int main(void)
{
	cout<<CGoods::getCount()<<endl;
	CGoods good(0,"good",2.5);
	cout<<CGoods::getCount()<<endl;
	good.printCGood();
	getName(good);
	CGoods good1(0,"good1",5.6);
	cout<<CGoods::getCount()<<endl;
	good1.printCGood();
	CGoods good2(good);
	cout<<CGoods::getCount()<<endl;
	good2.printCGood();
	cout<<getName(good1)<<endl;
	
	if (good1<good)
	{
		cout<<"good1<good"<<endl;
	}
	else
		cout<<"good1>=good"<<endl;

	if (good1>=good)
	{
		cout<<"good1>=good"<<endl;
	}
	else
		cout<<"good1<good"<<endl;

	return 0;
}