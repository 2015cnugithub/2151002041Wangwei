#include "worker.h"
using namespace std;

class Worker
{
protected:
	char *name;
	int age;
	int sex;//1:male,0:female
	double pay_per_hour;//10,20,40,30,50
public:

	Worker(char *i,int j,int k,double p);
	~Worker(){cout<<"Base delete func execute"<<endl;delete name;}
	virtual double Compute_pay(double)=0;
	friend ostream & operator<<(ostream &s, const Worker &worker)
	{
		s<<worker.name<<"\t";
		s<<worker.age<<"\t";
		if (worker.sex == 1)
			s<<"Male"<<"\t";
		else if (worker.sex == 0)
			s<<"Female"<<"\t";
		s<<worker.pay_per_hour;
		return s;
	}

	char *Name(){return name;}

};
Worker::Worker(char *i,int j,int k,double p)
{
	cout<<"Base create object func execute."<<endl;
	int len = strlen(i);
	name = new char[len+1];
	strcpy(name,i);
	age = j;
	sex = k;
	pay_per_hour = p;
}

class HourlyWorker:public Worker
{
public:
	HourlyWorker(char *i,int j,int k,double p);
	double Compute_pay(double hours);
};
HourlyWorker::HourlyWorker(char *i,int j,int k,double p):Worker(i,j,k,p)
{
	cout<<"HourlyWorker object creating func execute."<<endl;
}
double HourlyWorker::Compute_pay(double hours)
{
	double salary = 0.0;
	if (hours<=40)
		salary = pay_per_hour * hours;
	else if(hours>40)
		salary = pay_per_hour * 40 + 1.5*pay_per_hour*(hours-40);
	return salary;
}

class SalariedWorker:public Worker
{
public:
	SalariedWorker(char *i,int j,int k,double p);
	double Compute_pay(double hours);
};
SalariedWorker::SalariedWorker(char *i,int j,int k,double p):Worker(i,j,k,p)
{
	cout<<"SalariedWorker object creating func execute."<<endl;
}
double SalariedWorker::Compute_pay(double hours)
{
	double salary = 0.0;
	if(hours>=35)
		salary = pay_per_hour * 40;
	else if(0<hours<35)
		salary = pay_per_hour * hours + 0.5*pay_per_hour*(35-hours);
	return salary;
}

int main(void)
{
	char name[20];
	int age;
	int sex;//1:male,0:female
	char category;//'h':HourlyWorker,'s':SalariedWorker
	double salary_class;//10,20,40,30,50
	Worker *w[5];
	Worker *p_worker;
	int count = 0;
	char choice;
	bool quit=false;
	double work_time;
	while(count<5)
	{
		cout<<"Please input the worker's base information(Name,Age,Sex(0,1),Category('h','s'),Salary Classes(10,20,40,30,50)):"<<endl;
		cin>>name>>age>>sex>>category>>salary_class;
		if ((sex!=0&&sex!=1)||(category!='h'&&category!='s')||(salary_class!=10&&salary_class!=20&&salary_class!=40&&salary_class!=30&&salary_class!=50))
		{
			cout<<"Data doesn't meet requirement,please input again."<<endl;
			continue;
		}
		char *str = new char[strlen(name)+1];
		strcpy(str,name);
		
		if (category == 'h')
		{
			p_worker = new HourlyWorker(str,age,sex,salary_class);
		}
		else if (category == 's')
		{
			p_worker = new SalariedWorker(str,age,sex,salary_class);
		}
		w[count++] = p_worker;
		delete []str;
	}

	while (1)
	{
		cout<<"Please choice a worker: ";
		for(int i=0;i<5;++i)
		{
			cout<<"("<<i+1<<")"<<w[i]->Name();
		}
		cout<<endl;
		cin>>choice;
		switch(choice)
		{
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
			{
				int k= choice - '0';
				cout<<*(w[k-1])<<endl;
				cout<<"Please input working hours peer work: ";
				cin>>work_time;
				cout<<w[k-1]->Name()<<"weekly pay: "<<w[k-1]->Compute_pay(work_time)<<endl;
				break;
			}
		case 'q':quit=true;break;
		default:cout<<"Input errors,please input again."<<endl;
		}
		if(quit)
			break;
	}

	for(int i = 0;i<5;++i)
	{
		delete w[i];
	}

	return 0;
}