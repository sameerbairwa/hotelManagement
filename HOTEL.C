#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<bits/stdc++.h>
#include<windows.h>
int f2;
int scount = 0;
int dcount = 0;
int decount = 0;
int bill;
int single[10] = {100,101,102,103,104,105,106,106,108,109};
int doubl[10] = {200,201,202,203,204,205,206,207,208,209};
int deluxe[10] = {300,301,302,303,304,305,306,307,308,309};
int member = 0;
int top = -1;
int food[10] = {50,40,100,50,100,250,10,10,50,40};
int n,f;
struct checkout
{
	int roomNo;
	int day;
	int month;
	int year;
	int hour;
	int minute;
}c1,c2;
struct details
{
    int bill;
	int roomNo;
	char first[20];
	char last[20];
	char phone[11];
	struct date
	{
		int day;
		int month;
		int year;
	}d,da;
	struct time
	{
		int hour;
		int minute;
	}t,ta;
	char idtype[100];
	char id[40];
	char type[10];
}d1,s1;
struct checkinDate
	{
		int day;
		int month;
		int year;
		int hour;
		int minute;
	};
struct list
{
	char first[20];
	char last[20];
	int roomNo;
	struct checkinDate d;
	int bill;
	char type[20];
	struct list *next;
}*start = NULL;
FILE *f1,*l,*r;
void detail(int ,int ,char []);
void create(char [],char [],int ,int ,int ,int ,int ,int ,int ,char []);
int compute(char []);
void print();
void scan();
void read();
void checkout();
void del();
void time();
void foodMenu();
void calculate( int , int );
void display()
{
	struct list *a;
	a = start;
	while( a != NULL )
	{
		printf("%d\n",a->roomNo);
	    printf("%s ",a->first);
		printf("%s\n",a->last);
		printf("%d-%d-%d\n",a->d.day,a->d.month,a->d.year);
		printf("%d:%d\n",a->d.hour,a->d.minute);
		printf("%d\n",a->bill);
		printf("%s\n",a->type);
		a = a->next;
	}
}
int main()
{
    system("COLOR E");

	int m,a,b,room;
	read();
	startmenu:
        printf("\n\t\t\t\t\t\t****************************");
	    printf("\n\t\t\t\t\t\t  ** HOTEL MANAGEMENT **");
	    printf("\n\t\t\t\t\t\t****************************\n");
        printf("\t\t\t\t\t\t1.Administrator\n\t\t\t\t\t\t2.Customer\n\t\t\t\t\t\t3.Exit\n\n\t\t\t\t\t\tEnter choice: ");
	up:
	scanf("%d",&m);
	system("cls");
	switch( m )
	{
		case 1:
        printf("\n\t\t\t\t\t\t****************************");
	    printf("\n\t\t\t\t\t\t  ** HOTEL MANAGEMENT **");
	    printf("\n\t\t\t\t\t\t****************************\n");
		printf("\t\t\t\t\t\t1.Show customer details");
		printf("\n\t\t\t\t\t\t2.Check out");
		printf("\n\t\t\t\t\t\t3.Exit to main menu");
		up1:
		printf("\n\n\t\t\t\t\t\tEnter choice: ");
		scanf("%d",&a);
		switch(a)
		{
			case 1:scan();
			printf("Press any key for menu:");
			goto up;
			break;
			case 2:
			checkout();
			time();
			del();
			goto up;
			case 3:
            system("cls");
			goto startmenu;
			default:
			printf("wrong choice");
			goto up1;
		}
		break;
		case 2:
		up4:
       printf("\n\t\t\t\t\t\t****************************");
	    printf("\n\t\t\t\t\t\t  ** HOTEL MANAGEMENT **");
	    printf("\n\t\t\t\t\t\t****************************\n");
		printf("\t\t\t\t\t\t1.book a room\n\t\t\t\t\t\t2.food menu\n\t\t\t\t\t\t");
		printf("3.exit to main menu");
		up2:
		printf("\n\n\t\t\t\t\t\tEnter choice: ");
		scanf("%d",&b);
		system("cls");
		switch( b )
		{
			case 1:
            printf("\n\t\t\t\t\t\t****************************");
            printf("\n\t\t\t\t\t\t  ** HOTEL MANAGEMENT **");
            printf("\n\t\t\t\t\t\t****************************\n");
			printf("\t\t\tTypes of room       fixed charges    charges per day   availability\n");
			printf("\t\t\t1.single room     | 1000           | 3000             | %d\n",10-scount);
			printf("\t\t\t2.double room     | 1000           | 4000             | %d\n",10-dcount);
			printf("\t\t\t3.deluxe room     | 1000           | 5000             | %d\n",10-decount);
			up3:
			printf("\n\t\t\tEnter choice: ");
			scanf("%d",&room);
			switch( room )
			{
				case 1:n = compute("single");
				detail(n,1000,"single");
				printf("\n");
				goto up4;
				case 2:
				n = compute("double");
				printf("Member 1 details\n");
				detail(n,1000,"double");
				member++;
				printf("\nMember 2 details\n");
				detail(n,1000,"double");
				member = 0;
				printf("\n");
				goto up4;
				case 3:
				n = compute("deluxe");
				detail(n,1000,"deluxe");
				goto up4;
				default:
				printf("wrong choice");
				goto up3;
			}
			break;
			case 2:
			foodMenu();
			printf("Enter room no.: ");
			scanf("%d",&f2);
			printf("\nEnter choice: ");
			scanf("%d",&f);
			calculate(f2,f);
			goto up4;
			break;
			case 3:
			goto startmenu;
			default:
			printf("wrong choice");
			goto up2;
		}
		break;
		case 3:
		print();
		exit(0);
		default:
		printf("wrong choice");
		goto up;
	}
	return 0;
}
void foodMenu()
{
    FILE *y;
    int price;
    char item[30];
     printf("\n\t\t\t\t****************************");
    printf("\n\t\t\t\t  ** HOTEL MANAGEMENT **");
    printf("\n\t\t\t\t****************************\n");
    printf("\nFOOD MENU:\n\n");
    y = fopen("food.txt","r");
while( feof(y) == 0 )
{
    fscanf(y,"%s",&item);
    fscanf(y,"%d",&price);
    printf("%s %d\n",item,price);
}
fclose( y );
}
void create( char first[], char last[], int roomno, int day, int month, int year, int hour, int minute, int bill, char type[] )
{
	struct list *p,*tmp;
    tmp = (struct list *)malloc(sizeof(struct list));
	strcpy(tmp->first,first);
	strcpy(tmp->last,last);
	tmp->roomNo=roomno;
	tmp->d.day = day;
	tmp->d.month = month;
	tmp->d.year = year;
	tmp->d.hour = hour;
	tmp->d.minute = minute;
	tmp->bill = bill;
	strcpy(tmp->type,type);
	tmp->next = NULL;
	if( start == NULL )
		start = tmp;
	else
	{
		p = start;
		while( p->next != NULL )
			p = p->next;
		p->next = tmp;
	}
}
void detail( int room, int bill, char type[] )
{
	printf("\t\t\tEnter following details:\n");
	printf("\t\t\tFirst name: ");
	f1 = fopen("customer.txt","a+");
	fflush( stdin );
	gets( d1.first );
	printf("\t\t\tLast name: ");
	fflush( stdin );
	gets( d1.last );
	fprintf(f1,"%d\n",room);
	fprintf(f1,"%s %s\n",d1.first,d1.last);
	printf("\t\t\tPhone no.: ");
	fflush( stdin );
	gets( d1.phone );
	fprintf(f1,"%s\n",d1.phone);
	if( member == 0 )
	{
	    printf("\t\t\tDate(dd-mm-yyyy): ");
		fflush( stdin );
	    scanf("%d-%d-%d",&d1.d.day,&d1.d.month,&d1.d.year);
	    c2.day = d1.d.day;
	    c2.month = d1.d.month;
	    c2.year = d1.d.year;
	    fprintf( f1,"%d-%d-%d\n",d1.d.day,d1.d.month,d1.d.year );
	    printf("\t\t\tTime(24-hour format hh:mm ): ");
		fflush( stdin );
	    scanf("%d:%d",&d1.t.hour,&d1.t.minute);
	    c2.hour = d1.t.hour;
	    c2.minute = d1.t.minute;
		fflush( stdin );
	    fprintf(f1,"%d:%d\n",d1.t.hour,d1.t.minute);
		fflush( stdout );
	}
	else
	{
	    fprintf(f1,"%d-%d-%d\n",c2.day,c2.month,c2.year);
	    fprintf(f1,"%d:%d\n",c2.hour,c2.minute);
	}
	printf("\t\t\tId type: ");
	fflush( stdin );
	gets( d1.idtype );
	fprintf(f1,"%s\n",d1.idtype);
	printf("\t\t\tId number: ");
	fflush( stdin );
	gets( d1.id );
	fprintf(f1,"%s\n\n",d1.id);
	if( member == 0 )
	{
	    fflush( stdin );
		create(d1.first,d1.last,room,d1.d.day,d1.d.month,d1.d.year,d1.t.hour,d1.t.minute,bill,type);
	}
	printf("\t\t\tYou have been alloted room number:%d",room);
	if( member == 0 )
	{
		if( strcmp( type,"single" ) == 0 )
		    scount++;
	    else if( strcmp( type,"double" ) == 0 )
		    dcount++;
	    else if( type == "deluxe" )
		decount++;
	}
	fclose( f1 );
}
int compute( char type[] )
{
	int i,f=0;
	struct list *a;
	if( strcmp( type,"single" ) == 0 )
	{	for( i=0; i<10; i++ )
	    {
			 a = start;
		    while( a != NULL )
			{
				if( single[i] == a->roomNo )
				{
					f = 1;
					break;
				}
		    a = a->next;
			}
			if( f != 1 )
				break;
			f = 0;
	    }
		return single[i];
	}
	else if( strcmp( type,"double" ) == 0 )
	{
		for( i=0; i<10; i++ )
	    {
			a = start;
		    while(a != NULL )
			{
				if( doubl[i] == a->roomNo )
				{
					f = 1;
					break;
				}
		    a = a->next;
			}
			if( f != 1 )
				break;
			f = 0;
	    }
		return doubl[i];
	}
	else if( strcmp( type,"deluxe" ) == 0 )
	{
		for( i=0; i<10; i++ )
	    {
			a = start;
		    while( a != NULL )
			{
				if( deluxe[i] == a->roomNo )
				{
					f = 1;
					break;
				}
		    a = a->next;
			}
			if( f != 1 )
				break;
			f = 0;
	    }
		return deluxe[i];
	}
}
void print()
{
	struct list *a;
	a = start;
	l = fopen("list.txt","w");
	while( a != NULL )
	{
		fprintf( l, "\n%d\n",a->roomNo );
	    fprintf( l, "%s ",a->first );
		fprintf( l, "%s\n",a->last );
		fprintf( l, "%d-%d-%d\n",a->d.day,a->d.month,a->d.year );
		fprintf( l, "%d:%d\n",a->d.hour,a->d.minute );
		fprintf( l, "%d\n",a->bill );
		fprintf( l, "%s",a->type );
		a = a->next;
	}
	fclose( l );
}
void scan()
{
	struct details s;
	char strf[20];
	char strl[20];
    r = fopen("customer.txt","r");
	printf("\t\t\t\t\t\tEnter name of customer: ");
	fflush( stdin );
	scanf("%s %s",strf,strl);
	fflush( stdin );
		while( feof(r) == 0 )
		{
			fscanf( r, "%d",&s.roomNo );
			fscanf( r, "%s %s",s.first,s.last );
			fscanf( r, "%s",s.phone );
		    fscanf( r, "%d-%d-%d",&s.d.day,&s.d.month,&s.d.year );
		    fscanf( r, "%d:%d",&s.t.hour,&s.t.minute );
			fscanf( r, "%s",s.idtype );
			fscanf( r, "%s",s.id );
			fflush( stdout );
			fscanf( r, "%s",s.id );
			if( strcmp( strf,s.first ) == 0 && strcmp( strl,s.last ) == 0 )
			{
				printf("Room no.:%d\n",s.roomNo);
				printf("Name:%s %s\n",s.first,s.last);
				printf("Phone no.:%s\n",s.phone);
			    printf("Check in date:%d-%d-%d\n",s.d.day,s.d.month,s.d.year);
			    printf("Check in time:%d:%d\n",s.t.hour,s.t.minute);
				printf("Id type:%s\n",s.idtype);
				printf("Id no.:%s\n",s.id);
			}
		}
	fclose( r );
}
void read()
{
	FILE *x;
	x = fopen("list.txt","r");
	if( x != NULL )
	  {
	      while( !feof(x) )
		{
			fscanf( x, "%d",&s1.roomNo );
			if( s1.roomNo == 0 )
			break;
			fflush( stdin );
            fscanf( x, "%s %s",s1.first,s1.last );
			fscanf( x, "%d-%d-%d",&s1.da.day,&s1.da.month,&s1.da.year );
			fflush( stdout );
			fscanf( x, "%d:%d",&s1.ta.hour,&s1.ta.minute );
			fscanf( x, "%d",&s1.bill );
			fflush( stdin );
			fscanf( x, "%s",s1.type );
			create( s1.first, s1.last, s1.roomNo, s1.da.day, s1.da.month, s1.da.year, s1.ta.hour, s1.ta.minute, s1.bill, s1.type );
			if( strcmp( s1.type,"single" ) == 0 )
				scount++;
			else if( strcmp( s1.type,"double" ) == 0 )
				dcount++;
			else if( strcmp( s1.type,"deluxe" ) == 0 )
				decount++;
	    }
	  }
	fclose( x );
}
void checkout()
{
	printf("Room no.: ");
	scanf("%d",&c1.roomNo);
	printf("Date(dd-mm-yyyy): ");
	scanf("%d-%d-%d",&c1.day,&c1.month,&c1.year);
	fflush( stdin );
	printf("Time: ");
	scanf("%d:%d",&c1.hour,&c1.minute);
}
void del()
{
	int i,j = 0;
	struct list *p,*tmp,*prev;
	p = start;
    if( p != NULL && p->roomNo == c1.roomNo)
	{
	    start = p->next;
	    free( p );
	    return;
	}
	while( p != NULL && p->roomNo != c1.roomNo)
	{
        prev = p;
	    p = p->next;
	}
	if( p == NULL )
	{
	    return;
	}
	prev->next = p->next;
	free( p );
}
void time()
{
	struct list *p;
	int thour=0,tminute=0;
	p = start;
	while( p != NULL )
	{
		if( p->roomNo == c1.roomNo )
			break;
		p = p->next;
	}
	if( ( c1.year-p->d.year ) >= 2 )
	{
	    thour = thour + ( c1.year - p->d.year )*12*30*24;
		c1.year = p->d.year+1;
	}
	if( ( c1.year-p->d.year ) == 1 )
	{
	    if( c1.month > p->d.month )
	    {
	        thour = thour + (12*30*24);
	        c1.year--;
	    }
	    else
	    {
	        thour = thour + (c1.month)*30*24;
	        c1.year--;
	        c1.month == 12;
	        c1.day = 30;
	    }
	}
	if(( c1.month-p->d.month ) >= 2 )
	{
		thour = thour + ( c1.month - p->d.month - 1 )*30*24;
		c1.month = p->d.month + 1;
	}
	if( ( c1.month - p->d.month ) == 1 )
	{
	    if( c1.day > p->d.day )
	    {
	        thour = thour + (30*24);
	        c1.month--;
	    }
	    else
	    {
	        thour = thour + (c1.day)*24;
	        c1.day = 30;
	        c1.month--;
	    }
	}
	if( ( c1.day - p->d.day ) >= 2 )
	{
		thour = thour + ( c1.day - p->d.day - 1 )*24;
		c1.day = p->d.day + 1;
	}
	if( ( c1.day - p->d.day ) == 1 )
	{
	    if( c1.hour < p->d.hour )
	   {
		thour = thour + ( ( c1.hour+24 ) - ( p->d.hour ) );
		c1.day--;
	   }
	    else
	   {
		   thour = thour + 24 + ( c1.hour - p->d.hour );
		   c1.day--;
	   }
	}
	if( c1.day == p->d.day && c1.month == p->d.month )
	{
		if( c1.minute < p->d.minute )
		{
			thour = thour - 1;
			tminute = c1.minute + 60 - p->d.minute;
		}
		else
		{
			tminute = c1.minute - p->d.minute;
		}
	}
    if( strcmp( p->type, "single" ) == 0 )
    p->bill = p->bill + ( ( 3000/24 )*thour ) + ( ( 3000/(24*60 ) )*tminute );
    else if( strcmp( p->type,"double" ) == 0 )
     p->bill = p->bill + ( ( 4000/24 )*thour ) + ( ( 4000/(24*60 ) )*tminute );
    else if( strcmp( p->type,"deluxe" ) == 0 )
     p->bill = p->bill + ( ( 5000/24 )*thour ) + ( ( 5000/(24*60 ) )*tminute );
     printf("Bill:\nTotal amount to be paid:%d", p->bill);
}
void calculate( int f1, int f )
{
    struct list *p;
    p = start;
    while( p != NULL )
    {
        if( p->roomNo == f1 )
        break;
        p = p->next;
    }
    p->bill = p->bill + food[f];
}
