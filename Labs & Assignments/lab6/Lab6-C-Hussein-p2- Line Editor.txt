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
#define ESC 27
#define ENTER 13
#define BACKSPACE 8
#define MAX 101

void SetColor(int ForgC);
void gotoxy(int x,int y);
//---------------------------------------------------------------------------------------------------
int getLineLength();
void lineEditingMode(int lineLength, char line[]);

//---------------------------------------------------------------------------------------------------
int main()
{

    //getting line Length.
    int lineLength = getLineLength();
    //getting line.
    char line[MAX]={'\0'};
    fflush(stdin);

    fgets(line,MAX,stdin);
    printf(" line saved!\n");
    //showing line in Editing Mode.

    //running ( Line Editing Mode ) by while infinite loop.
    lineEditingMode(lineLength,line);
    //End of Logic.
    return 0;
}
//---------------------------------------------------------------------------------------------------
int getLineLength()
{
    int lineLength = 0 ;
    int validInput = 0;
    while( 0 == validInput || lineLength > 100 || lineLength < 1)
    {
        fflush(stdin);
        printf(" Enter line Length as number of characters between 1 and 100 : ");
        validInput = scanf("%d",&lineLength);
    }
    printf(" Your line Length is %d characters .\n Write your line: ",lineLength);
    return lineLength;
}

void lineEditingMode(int lineLength, char line[])
{
    int startPosition = 22, steps = 0, yPosition =10, xPosition;
    char x;
    gotoxy(0,yPosition-3);
    printf("\n Line Editing Mode...\n");
    while(1)
    {
        if(steps>lineLength-1)
        {
            steps = 0;
        }
        else if(steps<0)
        {
            steps = lineLength-1;
        }
        xPosition = startPosition + steps;
        gotoxy(startPosition,yPosition);
        SetColor(4);
        //
        for(int i=0; i<lineLength; i++)
        {
            printf("%c",line[i]);
        }
        SetColor(15);
        gotoxy(0,yPosition+3);
        printf("Press Enter to finish editing..");
        gotoxy(xPosition,yPosition);
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
                steps=0;
                break;
            case END:
                steps=lineLength-1;
                break;
            case ARROWUP:
                steps--;
                break;
            case ARROWLEFT:
                steps--;
                break;
            case ARROWDOWN:
                steps++;
                break;
            case ARROWRIGHT:
                steps++;
                break;
            }
            break;
        }
        case ESC:
        {
            return 0;
        }
        case ENTER:
        {
                gotoxy(0,yPosition-3);
            printf("\n please confirm ? Y/N\n");
            gotoxy(0,yPosition+5);
            printf("Your final line is :  ");
            SetColor(2);
            for(int i=0; i<lineLength; i++)
            {
                printf("%c",line[i]);
            }
            SetColor(15);
            gotoxy(0,yPosition+7);
            printf("Press \'Y\' for confirm, or \'N\' to more edit..");

            while(1)
            {
                x = getch();
                switch(x)
                {
                case ESC:
                {
                    return 0;
                }
                case 'Y':
                {
                    return 0;
                }
                case 'y':
                {
                    return 0;
                }
                case 'N':
                {
                    lineEditingMode(lineLength,line);
                }
                case 'n':
                {
                    lineEditingMode(lineLength,line);
                }
                default:
                {
                    break;
                }
                if(x=='N' || x=='n')
                {
                    main();
                }
                }
            }
            break;
        }
        case BACKSPACE:
        {
            break;
        }
        default:
        {
            if(x>=32 && x<=126 )
            {
                line[steps]=x;
                gotoxy(xPosition,yPosition);
                printf("x");
                steps++;
            }
            break;
        }
        }
    };
    printf("\n\n");
}



//---------------------------------------------------------------------------------------------------
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



