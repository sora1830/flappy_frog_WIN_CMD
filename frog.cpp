  #include <iostream>
#include <ctime>
#include <windows.h>
#include <conio.h>
#include <vector>
using namespace std;
void gotoxy(int x,int y)
{
	HANDLE h;
	COORD c;
	c.X=x;
	c.Y=y;
	h=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(h,c);
}
void hide_cursor()
{
	HANDLE	h_GAME = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor_info;
	GetConsoleCursorInfo(h_GAME,&cursor_info);
	cursor_info.bVisible=false;
	SetConsoleCursorInfo(h_GAME,&cursor_info);
}
class frog
{
public:
	int y,tt1,tt2,xb,a;
	double flag;
	clock_t t1,t2;
	frog()
	{
		y=12,tt1=200,t1=0,t2=0,tt2=400,xb=73,flag=0;
		a=rand()%15;
	}
	void glasses()
	{
		if(clock()-t1>tt1)
		{
			if(kbhit())
			{
				char cx;
				cx=getch();
				if(cx==32)
				{
					y-=5;
					gotoxy(30,y);  cout<<"┗□-□┛";
					gotoxy(30,y+5);cout<<"          ";
				}
			}
			++y;
			gotoxy(30,y-1);cout<<"          ";
			gotoxy(30,y);  cout<<"┗□-□┛";
			t1=clock();
		}
		if(((xb==31&&(y-a>=10||y-a<=0))||(xb==38&&(y-a>=10||y-a<=0)))||(y<1||y>24))
		{
			system("cls");
			gotoxy(30,12);cout<<"您为长者续了"<<flag*2<<"s";
			gotoxy(30,14);cout<<"您消耗了"<<clock()/1000<<"s的生命";
			gotoxy(30,16);cout<<"这个效率EFFIENCY是"<<(100*flag*2)/(t2/1000)<<"%\n";
			gotoxy(30,18);
			Sleep(1000);
			system("pause");
			exit(0);
			}
	}
	void block()
	{

		if(xb>=7)
			for(int j=0;j<24;j++)
			{
				if(a-j<10&&a-j>0){gotoxy(xb,j);cout<<"○○○";}
			}
		if(clock()-t2>tt2)
		{
			if(xb>=7) xb=xb-7;
			{
				for(int j=0;j<24;j++)
				{
					gotoxy(xb+7,j);cout<<"      ";
					if(j-a>10||j-a<0){gotoxy(xb,j);cout<<"○○○";}
				}
			}
			if(xb==3)
			{
				system("cls");
				a=rand()%17;
				xb=73;
				flag+=1;
				tt2-=10;
			}
			if(xb==73||xb==66||xb==59)
			{

			}
			t2=clock();
		}
		gotoxy(1,23);cout<<"我为长者续了"<<flag*2<<"s";
		gotoxy(1,24);cout<<"志己的生命减少了"<<clock()/1000<<"s   "<<"相对续命速度为"<<400-tt2;
	}
};

int main()
{
	hide_cursor();
	frog jzm;
	int i,j,k;
	for(i=0;i<=100;i+=4) {gotoxy(30,12);cout<<"程序的自我奋斗"<<i<<"%";     Sleep(40);}
	for(j=0;j<=100;j+=4) {gotoxy(30,14);cout<<"还要考虑历史的进程"<<j<<"%"; Sleep(40);}
	system("cls");
	gotoxy(20,4);cout<<"THIS GAME IS VERY EASY,";				  Sleep(300);
	gotoxy(20,7);cout<<"PRESS SPACE TO GET HIGHER,";             Sleep(300);
	gotoxy(20,10);cout<<"BUT DO NOT BE TOO HIGH OR TOO LOW";	  Sleep(300);
	gotoxy(20,13);cout<<"EVERY OBSTACLE YOU PASS,";               Sleep(300);
	gotoxy(20,16);cout<<"IS 1 SECOND THAT YOU DONATE TO ELDER!";  Sleep(300);
	gotoxy(20,19);cout<<"按任意键开始游(xu)戏(ming)";
	k=getch();
	system("cls");
	srand(time(NULL));
	while(true)
	{
		jzm.glasses();
		jzm.block();
	}
}
