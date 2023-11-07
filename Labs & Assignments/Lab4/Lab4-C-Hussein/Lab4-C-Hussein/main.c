#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define ROW 2
#define COL 3

int main()
{
    /*
    //1-Calculate average of each column in a 2D Array
    int arr[ROW][COL]= {0};
    int sum;
    float avg = 0;
    //get Input
    for(int i=0; i<ROW; i++)
    {
        sum = 0;
        for(int j=0; j<COL; j++)
        {
            printf("Enter element row %d col %d :",i,j);
            scanf("%d",&arr[i][j]);
            printf(" scanned \n");
        }

    }
    //implementation
    for(int j=0; j<COL; j++)
    {
        sum = 0;
        for(int i=0; i<ROW; i++)
        {
            sum += arr[i][j];
        }
        avg= (float)sum/ROW;
        printf("the average for column %d = %f \n",j,avg);
    }
    */

    /*
    //2- C Program to add two matrix and put the result in a third one, then print the result
    int a[ROW][COL], b[ROW][COL], sum[ROW][COL], i, j;
    printf("C Program to add two matrix and put the result in a third one:- ");


    printf("\nEnter elements of 1st matrix:\n");
    for (i = 0; i < ROW; ++i)
        for (j = 0; j < COL; ++j)
        {
            printf("Enter element a%d%d: ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }

    printf("Enter elements of 2nd matrix:\n");
    for (i = 0; i < ROW; ++i)
        for (j = 0; j < COL; ++j)
        {
            printf("Enter element b%d%d: ", i + 1, j + 1);
            scanf("%d", &b[i][j]);
        }

    // adding two matrices
    for (i = 0; i < ROW; ++i)
        for (j = 0; j < COL; ++j)
        {
            sum[i][j] = a[i][j] + b[i][j];
        }

    // printing the result
    printf("\nSum of two matrices: \n");
    for (i = 0; i < ROW; ++i)
        for (j = 0; j < COL; ++j)
        {
            printf("%d   ", sum[i][j]);
            if (j == COL - 1)
            {
                printf("\n\n");
            }
        }
    */


    /*
    //3- Receive character by character and then place the string terminator upon pressing enter, then display the string.
    printf("\n Write any string \n ");
    char arr[100];
    int i=0;
    do
    {
        arr[i] = getche();
        i++;
    }
    while( 13 != arr[i-1] );
    arr[i]='\0';
    printf("\n your string is\n %s \n",arr);
    */

    /*
    //4- C Program to take char and displays if it is "Normal or Extended key" along with its Ascii value.
    char x;
    printf("\n Enter any key: ");
    x = getch();
    switch (x)
    {
    case -32:
        printf("\n Extended key \n");
        break;
    default:
        printf("\n Normal key \n");
        break;
    }
    */

    /*
    //5- C Program to take firstName and lastName from user, then displays fullName.
    char arr1[50]={}, arr2[50]={}, arr[100]={};
    int i=0,j=0,k=0,m=0;
    printf("\n Write first name \n ");
    do
    {
        arr1[i] = getche();
        i++;
    }
    while( 13 != arr1[i-1] );
    i--;
    arr1[i]='\0';

    printf("\n Write last name \n ");
    do
    {
        arr2[j] = getche();
        j++;
    }
    while( 13 != arr2[j-1] );
    j--;
    arr2[j]='\0';

    for(k=0; k<i; k++)
    {
        arr[k]=arr1[k];
    }
    arr[i]=' ';
    for(k=i+1,m=0; m<j; k++,m++)
    {
        arr[k]=arr2[m];
    }
    arr[k+1]='\0';
    printf("\n\n your full name is\n %s \n",arr);
    */

    //6- menu (in seperated file)


    /*
    //7- C Program to Find the Frequency of Characters in a String
    char str[100], ch;
    int count=0, i=0,j=0;
    //get string
    printf("Enter a string: ");
    do
    {
        str[i] = getche();
        i++;
    }
    while( 13 != str[i-1] );
    i--;
    str[i]='\0';
    //Implementation
    printf("Enter a character to find its frequency: ");
    ch = getche();

    for ( j=0; str[j] != '\0'; j++)
    {
        if (ch == str[j])
            count++;
    }
    printf("\nFrequency of %c = %d \n", ch, count);
    */


    /*
    //8- C Program to Copy String Without Using strcpy()
    char str[50],strcopy[50]={};
    int i=0, j=0;
    //get string
    printf("Enter a string: ");
    do
    {
        str[i] = getche();
        i++;
    }
    while( 13 != str[i-1] );
    i--;
    str[i]='\0';
    //Implementation
    for( j=0; str[j]!='\0' ;j++)
    {
        strcopy[j]=str[j];
    }
    strcopy[j+1]='\0';
    printf("the original : %s \n",str);
    printf("the copy is  : %s \n",strcopy);
    */

    /*
    //9- C Program to Find the Length of a String without Using strlen()
    char str[50];
    int i=0, length=0;
    //get string
    printf("Enter a string: ");
    do
    {
        str[i] = getche();
        i++;
    }
    while( 13 != str[i-1] );
    i--;
    str[i]='\0';
    //Implementation of getting length
    for( length=0; str[length]!='\0' ;length++)
    {
    }
    printf("\n the length is : %d \n",length);
    */

    /*
    //10- C Program to Remove all Characters in a String Except Alphabet.
    char str[50],strAlpha[50]= {};
    int i=0, j=0, k=0;
    //get string
    printf("Enter a string: ");
    do
    {
        str[i] = getche();
        i++;
    }
    while( 13 != str[i-1] );
    i--;
    str[i]='\0';
    //Implementation
    for( j=0; str[j]!='\0' ; j++)
    {
        if( 32==str[j] || (str[j]>=65 && str[j]<=90 ) || (str[j]>=97 && str[j]<=122 ) )
        {
            strAlpha[k]=str[j];
            k++;
        }
    }
    strAlpha[j+1]='\0';
    printf("the original : %s \n",str);
    printf("the strAlpha : %s \n",strAlpha);
    */

    /*
    //11- C Program to Convert all Characters in a String to Capital Case.
    char str[50],strCap[50]= {};
    int i=0, j=0, k=0;
    //get string
    printf("Enter a string: ");
    do
    {
        str[i] = getche();
        i++;
    }
    while( 13 != str[i-1] );
    i--;
    str[i]='\0';
    //Implementation
    for( j=0; str[j]!='\0' ; j++)
    {
        if( str[j]>=97 && str[j]<=122  )
        {
            strCap[j]=(str[j]-32);
        }
        else
        {
            strCap[j]=str[j];
        }
    }
    strCap[j+1]='\0';
    printf("the  original  : %s \n",str);
    printf("the strCapital : %s \n",strCap);
    */

    //- for the question of using space in a string we can use
    //  a function like gets(str); instead of scanf("%s",str); .

    printf("\n\n");
    return 0;
}
