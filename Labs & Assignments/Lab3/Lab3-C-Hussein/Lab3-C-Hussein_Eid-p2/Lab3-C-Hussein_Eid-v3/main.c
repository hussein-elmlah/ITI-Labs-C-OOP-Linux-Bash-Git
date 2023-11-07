#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#include <time.h>
#define SIZE 10
void gotoxy(int x,int y)
{
    COORD coord= {0,0};
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
int main()
{

    //1- Magic Box
    int i,j,row,col,size;
    printf("Enter Number of Rows in odd number\n");
    scanf("%d",&size);

    if(size%2!=0)
    {
        printf("Magic Square for %d rows is\n",size);
        row=0;
        col=size/2;
        //    int a[size][size];
        for(i=1; i<=size*size; i++)
        {
            gotoxy(5*col+5,3*row+5);
            printf("%d",i);
            sleep(1);
            col++;
            row--;
            if(i%size==0)
            {
                col=col-1;
                row=row+2;
            }
            if(col==size)
            {
                col=0;
            }
            if(row==-1)
            {
                row=size-1;
            }
        }
        printf("\n\n");
    }
    else
    {
        printf("Please Enter Odd Number to get Magic Square\n");
    }


    /*
    // 2- C Program to take an array elements from user,
    //  then print them out "using 2 for loops". (Print Array)
    int arr[SIZE];
    printf("\n take an array elements from user, then print them out:\n");
    printf("Enter 10 elements in the array :\n");
    for(int i=0; i<SIZE; i++)
    {
        printf("Enter element %d : ",i+1);
        scanf("%d", &arr[i]);
    }
    printf("\nElements in array are: ");
    for(int i=0; i<SIZE; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");
    */

    /*
    // 3- C Program to find the minimum & maximum value of array elements. (Min_Max Array)
    int arr1[SIZE];
    int max, min, n;
    printf("\n\nfind the minimum & maximum value of array elements :\n");
    printf("Enter 10 elements in the array :\n");
    for(int i=0; i<SIZE; i++)
    {
        printf("element %d : ",i);
        scanf("%d",&arr1[i]);
    }
    max = arr1[0];
    min = arr1[0];
    for(int i=1; i<SIZE; i++)
    {
        if(arr1[i]>max)
        {
            max = arr1[i];
        }
        if(arr1[i]<min)
        {
            min = arr1[i];
        }
    }
    printf("\n Maximum is : %d\n", max);
    printf("\n Minimum is : %d\n", min);
    */


    return 0;
}
