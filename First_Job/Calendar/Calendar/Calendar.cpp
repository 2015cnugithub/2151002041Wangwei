#include "Calendar.h"

int calWeekOfFirstDay(int,int);
int calDayNum(int,int);
void printCalendar(int,int,int,int);
int main(void)
{
	int year;
	int month;
	int firstday;
	int daynum;

	int quit = 0;

	while(1)
	{
		char choice;
		printf("Please Enter your choice(c or q):");
		scanf("%c",&choice);
		fflush(stdin);

		switch(choice)
		{
		case 'c':
			{
				printf("Please Enter year, month: ");
				scanf("%d %d",&year,&month);
				fflush(stdin);
				firstday = calWeekOfFirstDay(year,month);
				daynum = calDayNum(year,month);

				printCalendar(year,month,firstday,daynum);
				printf("\n");
				break;
			}
		case 'q':quit = 1;break;
		default:printf("Your choice is wrong\n");break;
		}

		if (quit)break;
	}

	return 0;
}

int calWeekOfFirstDay(int year,int month)
{
	int c,y,m,w;
	int d = 1;
	if(month == 1)
	{
		month = 13;
		year -= 1;
	}
	else if (month == 2)
	{
		month = 14;
		year -= 1;
	}

	c = year /100;
	y = year % 100;
	m = month;

	//zeller��ʽ w = ([c/4] -2c + y + [y/4] + [13*(m+1)/5] + d -1)%7

	w = (c/4 -2*c + y + y/4 + (13*(m+1))/5 + d - 1)%7;

	w = (w>=0)?w:(w+7);

	return w;

}

int calDayNum(int year,int month)
{
	int dayNum = 30;
	switch (month)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
		{
			dayNum = 31;
			break;
		}
		case 2:
			{
				dayNum = year%(year%100?400:4)?29:28;
				break;
			}
		default:break;
	}

	return dayNum;
}

void printCalendar(int year,int month,int firstday,int daynum)
{
	char * monthName = NULL;
	switch(month)
	{
	case 1:monthName = "January";break;
	case 2:monthName = "February";break;
	case 3:monthName = "March";break;
	case 4:monthName = "April";break;
	case 5:monthName = "May";break;
	case 6:monthName = "June";break;
	case 7:monthName = "July";break;
	case 8:monthName = "August";break;
	case 9:monthName = "September";break;
	case 10:monthName = "October";break;
	case 11:monthName = "November";break;
	case 12:monthName = "December";break;
	default:monthName = " ";break;
	}

	printf("%40s, %d\n",monthName,year);
	printf("%10s %10s %10s %10s %10s %10s %10s\n","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday");

	switch(firstday)
	{
		case 0:printf("%66s","");break;
		case 1:break;
		case 2:printf("%11s","");break;
		case 3:printf("%22s","");break;
		case 4:printf("%33s","");break;
		case 5:printf("%44s","");break;
		case 6:printf("%55s","");break;
	}


	for(int i = 0;i<daynum;++i)
	{
		if ((firstday+i)%7==0)
		{
			printf("%10d\n",i+1);
		}
		else
		{
			printf("%10d ",i+1);
		}
	}
}