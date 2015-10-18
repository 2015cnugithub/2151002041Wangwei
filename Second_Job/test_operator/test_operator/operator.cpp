#include "operator.h"
using namespace std;

class CGoods{
public:
	CGoods(long number=0,char *name="",double p=0.0){no = number;P_name = new char[strlen(name)+1];strcpy(P_name,name);price = p;++count;cout<<"Creating object function execute"<<endl;}//构造函数
	CGoods(const CGoods &a){no = a.no;P_name = new char[strlen(a.P_name)+1];strcpy(P_name,a.P_name);price = a.price;++count;cout<<"Copy object function executive"<<endl;}//拷贝构造函数
	~CGoods(){--count;delete P_name;P_name = NULL;cout<<"Delete object function executive"<<endl;}//析构函数
	void printCGood()const{cout<<no<<"\t"<<P_name<<"\t"<<price<<endl;};//打印数据成员的函数
	static int getCount(){return count;}//获取商品总数函数
	friend char* getName(const CGoods &a);

	//重载小于运算符
	bool operator<(const CGoods &a){
		if(price<a.price)
			return true;
		else
			return false;
	}

	//重载大于等于运算符
	bool operator>=(const CGoods &a){
		if (price>=a.price)
			return true;
		else
			return false;
	}

private:
	long no;//商品号
	char *P_name;//商品名
	double price;//商品价格
	static int count;//商品总数

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