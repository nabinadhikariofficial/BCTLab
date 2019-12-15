#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>

float x1,y1,x2,y2,x3,y3,m,b;

float calcx(float x,int ch)
{
	float mul,p,q;
	mul=1/(m*m+1);
	if(ch==1)
	{
		p=x1;
		q=y1;
	}
	else if(ch==2)
	{
		p=x2;
		q=y2;
	}
	else
	{
		p=x3;
		q=y3;
	}
	x=mul*(p*(1-m*m)+2*m*q-2*b*m);
	return x;
}

float calcy(float y,int ch)
{
	float mul,p,q;
	mul=1/(m*m+1);
	if(ch==1)
	{
		p=x1;
		q=y1;
	}
	else if(ch==2)
	{
		p=x2;
		q=y2;
	}
	else
	{
		p=x3;
		q=y3;
	}
	y=mul*((2*m*p)+(m*m-1)*q+2*b);
	return y;
}

void main()
{
	int gd=DETECT,gm;
	char a;
	clrscr();
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	printf("\n enter the coordinates of triangle");
	scanf("%f%f%f%f%f%f",&x1,&y1,&x2,&y2,&x3,&y3);

	line(x1+320,y1+220,x2+320,y2+220);
	line(x2+320,y2+220,x3+320,y3+220);
	line(x3+320,y3+220,x1+320,y1+220);

	line(320,0,320,440);
	line(0,220,640,220);

	printf("enter the vlue of (m and b) for y=mx+b");
	scanf("%f%f",&m,&b);
	printf("\n triangle after reflection");
	line(calcx(x1,1)+320,calcy(y1,1)+220,calcx(x2,2)+320,calcy(y2,2)+220);
	line(calcx(x2,2)+320,calcy(y2,2)+220,calcx(x3,3)+320,calcy(y3,3)+220);
	line(calcx(x3,3)+320,calcy(y3,3)+220,calcx(x1,1)+320,calcy(y1,1)+220);
	getch();
	closegraph();
}
