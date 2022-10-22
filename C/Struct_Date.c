#include<stdio.h>
//typedef 
//typedef int week;
typedef struct date
{
	int day;
	int month;
	int year;
}date;

const int months_normal [] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int months_leap[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int leap_year (date d)
{
	if ( ( (d.year % 400 )== 0) || ( (d.year%4==0) && (d.year%100!=0)) )
	return 1;
	return 0;
}

int check_equal(date d1, date d2)
{
	d1.day = 2;
	if( (d1.day==d2.day) && (d1.month==d2.month) && (d1.year==d2.year) )
	return 1;
	return 0;
}
void read_date(date* d)
{
		scanf("%d-%d-%d",&d->day,&d->month,&d->year);
}
void print(date d)
{
	printf("Day is %d month is %d Year%d",d.day,d.month,d.year);
}
void increment(date *d)
{
	const int *months;
	if (leap_year(*d) )
	months = months_leap;
	else
	months = months_normal;
	if (++(d->day) > months[d->month-1] )
	{
		d->month++;
		d->day=1;	
		if (d->month>12)
		{
			//d->day = 1;
			d->month = 1;
			d->year ++;
		}
	}
}

date add_date(date d, int num_days)
{
	date new_day;
	const int *months;	
//	int rem_days;
	if (leap_year(d) )
	months = months_leap;
	else
	months = months_normal;
	new_day.day = d.day + num_days;
	new_day.month = d.month;
	new_day.year = d.year;	
	while (new_day.day > months[new_day.month-1])
	{
		if (leap_year(new_day) )
		months = months_leap;
		else
		months = months_normal;
		new_day.day=new_day.day - months[new_day.month-1];	
		new_day.month++;
		if (new_day.month>12)
		{
			new_day.month = 1;
			new_day.year ++;
		}
	}
	return new_day;
}


int main()
{
	date d1,d2;
	read_date(&d1);
	//increment(&d1);
	d2 = add_date(d1,1460);
	print(d2);
	//read_date(&d2);
	/*if(check_equal(d1,d2)==1)
	printf("Same date");
	else
	printf("Different dates");
	//printf("\nDay is %d Month is %d Year is %d",d1.day,d1.month,d1.year);
	//week w;
	//scanf("%d",&w);*/
}
