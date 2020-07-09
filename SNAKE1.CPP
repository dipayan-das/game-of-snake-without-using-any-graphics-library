#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
void main()
{
clrscr();
int i,j,horizn=3,vertical=1,up=0,right=1,flag=0,u=79,binglvl=10,bingsd=70,last=0;
int counter=0,counter2=0,s=4,h[36]={3,2,1,0},v[36]={1,1,1,1},strlvl=10,strsd=40,ms=300;
char b,a[24][79],c[30];

for( ; ; )
{
for(i=0;i<24;i++)
{ for(j=0;j<u;j++)
 if(  ( (counter/5==1)&&((i==5||i==18)&&29<j&&j<49) ) || ( (counter/5==2)&&((j==29||j==49)&&5<i&&i<18) ) || ( (counter/5==3)&& (((i==5||i==18) &&29<j&&j<49) || ((j==9||j==69)&&5<i&&i<18)) )  )
     { a[i][j]='#'; }
 else
     { a[i][j]=' '; }
}
a[strlvl][strsd]='*';
if( ((160<last&&last<220)&&counter2==0)||((170<last&&last<230)&&counter2==1)||((180<last&&last<240)&&counter2==2) )
{ a[binglvl][bingsd]='@'; }
c[0]='0'; c[s-1]='+';
for(i=1;i<s-1;i++)
{ c[i]='O'; }

if (kbhit())
{
 b=getch();
 switch(b)
  {
   case 'w':  if(up!=1)
	     { up=-1;right=0;}
		break;
   case 'a':  if(right!=1)
	     { up=0;right=-1;}
		break;
   case 's':  if(up!=-1)
	     {  up=1;right=0;}
		break;
   case 'd':  if(right!=-1)
	     {  up=0;right=1;}
		break;
   default: flag=1;
  }
}
   if(counter==20)
 { printf("/n/n\tY O U    H A V E    M A S T E R E D    S N A K E\n"); delay(1300); flag=1;  }
  if(flag==1)
   { printf("\n\n\t\t=====YOUR SCORE IS %d =====\n\n\n\t\t=====BONUS POINT %d =====",counter,counter2); delay(1300);break;  }
horizn += right;   vertical += up;
 if(horizn>u-1)
  {   horizn=1;    }
  if(horizn<1)
  {   horizn=u-1;  }
  if(vertical>23)
  {   vertical=1;  }
  if(vertical<1)
  {   vertical=23; }

  for(i=s-1;i>0;i--)
  {      h[i]=h[i-1];   v[i]=v[i-1];     }
  h[0]=horizn;    v[0]=vertical;

  for(i=1;i<s;i++)
  {   if((h[0]==h[i]&&v[0]==v[i])||(a[v[0]][h[0]]=='#'))
   {     flag=1;     }
  }
  for(i=0;i<s;i++)
  {      a[v[i]][h[i]]=c[i];    }
for(i=0;i<24;i++)
{
  for(j=0;j<u;j++)
  {      printf("%c",a[i][j]);     }
  printf("\n");
}
  if(horizn==strsd&&vertical==strlvl)
  { do { strsd=rand()%u+1; strlvl=rand()%24+1;} while(a[strlvl][strsd]!=' ');
  counter++;
  if(ms>40)  {  ms=ms-20; }  s++;  if(s>25) {s--;}
  }
  if(horizn==bingsd&&vertical==binglvl)
  { counter2++;last=0;}
last++;     delay(ms);     clrscr();
}
getch();
}