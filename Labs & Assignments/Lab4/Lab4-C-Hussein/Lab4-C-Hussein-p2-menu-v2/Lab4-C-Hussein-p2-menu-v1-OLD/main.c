#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <dos.h>
#include <dir.h>
#define ARROWUP 72
#define ARROWDOWN 80
#define ARROWRIGHT 77
#define ARROWLEFT 75
#define HOME 71
#define END 79

int flag=0;

void SetColor(int ForgC)
{
    WORD wColor;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    //We use csbi for the wAttributes word.
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        //Mask out all but the background attribute, and add in the forgournd     color
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}
void gotoxy(int x,int y)
{
    COORD coord= {0,0};
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
//--------------------------------------------------------------------------------
void position1()
{
    system("cls");
    printf(" position1");
    gotoxy(20,7);
    SetColor(4);
    printf("New");
    SetColor(15);
    gotoxy(20,14);
    printf("Display");
    gotoxy(20,21);
    printf("Exit");
    gotoxy(0,0);
    flag=1;
}
void position2()
{
    system("cls");
    printf(" position2");
    gotoxy(20,7);
    printf("New");
    gotoxy(20,14);
    SetColor(4);
    printf("Display");
    gotoxy(20,21);
    SetColor(15);
    printf("Exit");
    gotoxy(0,0);
    flag=2;
}
void position3()
{
    system("cls");
    printf(" position3");
    gotoxy(20,7);
    printf("New");
    gotoxy(20,14);
    printf("Display");
    gotoxy(20,21);
    SetColor(4);
    printf("Exit");
    SetColor(15);
    gotoxy(0,0);
    flag=3;
}
void enterNew()
{

}

int main()
{

    char y=0;
    char x;


    position1();
    do
    {
        x = getch();
        printf("\n %d \n",x);
        if(HOME==x)
        {
            position1();
        }
        if(END==x)
        {
            position3();
        }
        if((ARROWUP==x || ARROWLEFT==x) && 2==flag)
        {
            position1();
        }
        if((ARROWUP==x || ARROWLEFT==x) && 3==flag)
        {
            position2();
        }
        if((ARROWDOWN==x || ARROWRIGHT==x) && 1==flag)
        {
            position2();
        }
        if((ARROWDOWN==x || ARROWRIGHT==x) && 2==flag)
        {
            position3();
        }


    }
    while(1);
    position2();
    position3();


    printf("\n\n");
    return 0;
}
