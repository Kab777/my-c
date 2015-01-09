#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<math.h>
#define LEN 112
#define HIGH 37
#define I 20 
#define R 340
int flag;
int key;
int counter=1;
void gotoxy(short x, short y)
{ 
	COORD c={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c); 
}
struct node
{ 
	int x,y; 
};
struct node *p,*q;
struct Food
{
	int x;
	int y;
	int yes;
}food;

int control()
{ 
	    if(counter!=0)
		{
			gotoxy(0,0);
			printf("Score:%d\b\b",counter);
			gotoxy(0,1);
			printf("%c%c%c%c%c",30,30,30,30,30);                       
		}
		if(food.yes==1)
		{
			food.x=rand()%112+1;//这里没用宏定义代替数值，防止不会出现食物的bug
			food.y=rand()%37+1;
			food.yes=0;
		}
		if(food.yes==0)
		{
			gotoxy(food.x,food.y);	
			printf("%c",3);
		}
		if (flag == 0)
		{
			key = getch();
		}
		if (kbhit())
		{
			key = getch(); 
		}
		q->x=p->x;q->y=p->y;
		switch(key) 
		{ 
		case 'a':(p->x)--;  break; 
		case 'd':(p->x)++;  break; 
		case 's':(p->y)++;  break; 
		case 'w':(p->y)--; 
		}
		gotoxy(p->x,p->y);
		printf("%c",2);
		if(p->x>LEN||p->y>HIGH||p->x<0||p->y<0)
		{
			system("cls");
			gotoxy(LEN/2,HIGH/2);
			printf("gameover\n");
			Sleep(3000);
			return 0;
		}
		gotoxy(q->x,q->y);
		printf(" ");
		Sleep(100); 
		gotoxy(p->x,p->y); 
		if(p->x==food.x&&p->y==food.y)
		{
			system("color E5");
			food.yes=1;
			counter++;
		}
		flag ++;
	return control();
}

int main()
{
	
	food.yes=1;
	srand(time(NULL));
	system("title JY GAME");
	system("mode con cols=112 lines=37");
	system("color E5");
	gotoxy(LEN/2,HIGH/2);
	printf("%c",2);
	p=(struct node*)malloc(sizeof(struct node));  
	q=(struct node*)malloc(sizeof(struct node)); 
	p->x=LEN/2,p->y=HIGH/2;
	flag = 0;
	control();		
}//actually this my first game,inevitable that's not so good,however,i hope you guy will like it.