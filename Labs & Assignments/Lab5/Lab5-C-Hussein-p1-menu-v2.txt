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

typedef unsigned char  u8;
typedef signed char  s8;
typedef unsigned short int  u16;
typedef signed short int  s16;
typedef unsigned long int  u32;
typedef signed long int  s32;

int studentCounter=0;

struct student
{
    u8 name[10];
    u8 gender;
    u8 age;
    s32 id;
};
void display_struct_Student(struct student s);
int scan_struct_Students(struct student s[],int size);
int print_struct_Students(struct student s[],int size);


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
//---------------------------------------------------------------------------------------------------
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

int enter(int *flag, struct student students[])
{
    char c;
    system("cls");
    //printf(" enter");
    //gotoxy(20,7);
    switch(*flag)
    {
    case 1:
    {
        printf("New student\n");
        while(c!=27)
        {
            printf("Do you want to add student Y/N: \n");
            c=getch();
            if(c=='Y' || c=='y')
            {
                scan_struct_Students(students,1);
            }
            else if(c=='N' || c=='n' || c==27)
            {
                return -1;
            }
        }
        break;
    }

    case 2:
    {
        //printf("Display");
        print_struct_Students(students,studentCounter);
        printf("\n studentCounter = %d \n",studentCounter);
        break;
    }

    case 3:
    {
        printf("Do you want to exit Y/N ? ");
        do
        {
            char c=getch();
            if(c=='Y' || c=='y')
            {
                return 1;
            }
            else if(c=='N' || c=='n')
            {
                return -1;
            }
            else
            {

            }
        }
        while(1);
        break;
    }
    }
    return 0;
}

int main()
{
    struct student students[100];

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
            switch(enter(&flag,students))
            {
            case 1:
            {
                return 0;
            }
            case -1:
            {
                position(&flag);
            }
            default:
            {
                break;
            }


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

//---------------------------------------------------------------------------------------------------

int scan_struct_Students(struct student s[],int size)
{
        int i = studentCounter;
        int sNum = studentCounter+1;
        printf("Enter Student %d :\n",sNum);
        printf("Enter name [%d]",i+1);
        scanf("%s",s[i].name);
        printf("Enter age [%d]",i+1);
        scanf("%d",&s[i].age);
        printf("Enter ID [%d]",i+1);
        scanf("%d",&s[i].id);
        printf("Enter Gender [%d]",i+1);
        scanf(" %c",&s[i].gender);
        studentCounter++;
    return 0;
}
int print_struct_Students(struct student s[], int size )
{
    printf("----------------- Display -------------------- \n");
    for(int i=0; i<studentCounter; i++)
    {
        printf("Student %d \n",i+1);
        printf("name[%d] = %s \n",i+1,s[i].name);
        printf("gender[%d] = %c \n",i+1,s[i].gender);
        printf("age [%d]=  %d \n",i+1,s[i].age);
        printf("id [%d] =  %d \n\n",i+1,s[i].id);
    }
    return 0;
}

/*
    struct student s1= {"mina",'m',10,3000};
    struct student students[100];
    scan_struct_Students(students,3);
    print_struct_Students(students,3);
*/
