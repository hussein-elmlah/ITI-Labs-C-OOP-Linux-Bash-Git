#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <dos.h>
#include <dir.h>
#include <conio.h>

#define ARROWUP 72
#define ARROWDOWN 80
#define ARROWRIGHT 77
#define ARROWLEFT 75
#define HOME 71
#define END 79

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
void position(int *flag)
{
    //flag configuration for 3 positions only.
    switch (*flag)
    {
    case 0:
        *flag = 3;
        break;
    case 4:
        *flag = 1;
        break;
    }
    //reposition by flag.
    switch(*flag)
    {
    case 1:
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
        break;
    case 2:
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
        break;
    case 3:
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
        break;
    }
}

int enter(int *flag)
{
    system("cls");
    printf(" enter");
    gotoxy(20,7);
    switch(*flag)
    {
    case 1:
        printf("New");
        break;
    case 2:
        printf("Display");
        break;
    case 3:
        system("cls");
        return 1;
    }
    return 0;
}

int main()
{
    char x;
    int flag=1;
    //initialize position
    position(&flag);
    //running program by while infinite loop.
    while(1)
    {
        //character input mapping.
        x = getch();
        switch(x)
        {
        case -32:
        {
            x = getch();
            switch(x)
            {
            case HOME:
                flag=1;
                position(&flag);
                break;
            case END:
                flag=3;
                position(&flag);
                break;
            case ARROWUP:
                flag--;
                position(&flag);
                break;
            case ARROWLEFT:
                flag--;
                position(&flag);
                break;
            case ARROWDOWN:
                flag++;
                position(&flag);
                break;
            case ARROWRIGHT:
                flag++;
                position(&flag);
                break;
            }
            break;
        }
        case 27:
        {
            position(&flag);
            break;
        }
        case 13:
        {
            if(enter(&flag))
            {
                return 0;
            }
            break;
        }
        default:
        {
            break;
        }
        }
    };


    printf("\n\n");
    return 0;
}
