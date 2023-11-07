#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//1- Function gives the cube of any number.
int  cube(int n)
{
    printf("\n the cubic number of %d = %d \n",n, n*n*n);
    return n*n*n;
}
//2- Function checks if it alphabet or not.
int is_alpha(char ch)
{
    if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
    {
        printf("\n Character is an alphabet.\n");
        return 1;
    }
    else
    {
        printf("\n Character is not alphabet.\n");
        return 0;
    }
}
//3- Function that check if the number if positive or negative.
int ispositive(int x)
{
    if(x>0)
    {
        printf("\n the number is positive.\n");
        return 1;
    }
    else if(x<0)
    {
        printf("\n the number is negative.\n");
        return -1;
    }
    else
    {
        printf("\n the number is zero.\n");
        return 0;
    }
}
//4- simple calculator.
float calcul(float num1, float num2, char opr)
{
    float res= 0;

    switch(opr)
    {
    case '+':
        res = num1+num2;
        printf("\n Addition = %f", res);
        return res;
    case '-':
        res = num1-num2;
        printf("\n Subtraction = %f", res);
        return res;
    case '*':
        res = num1*num2;
        printf("\n Multiplication = %f", res);
        return res;
    case '/':
        if(0==num2)
        {
            printf("\n \"zero division exception\" \n");
            return -1;
        }
        res = (float)num1/num2;
        printf("\n Division = %f \n\n", res);
        return res;
    default:
        printf(" an invalid Input.");
        return -1;
    }
}
//5-check if even or odd
int checkodd(int b)
{
    if(0==b%2)
    {
        printf("\n the number is even \n");
        return 0;
    }
    else if(1==b%2)
    {
        printf("\n the number is odd \n");
        return 1;
    }
    else
    {
        printf("\n Error \n");
        return -1;
    }
}
//6- Function that converts the any letter from lowercase to uppercase.
int getUpper(char ch)
{
    if(ch >= 'a' && ch <= 'z')
    {
        ch -= 32;
        printf("\n converted %c to %c \n",ch+32,ch);
        return ch;
    }
    else
    {
        printf("\n the key %c isn\'t lower case \n",ch);
        return ch;
    }
}
//7- Function that reads two integers and checks if the first is multiple of the second.
int isMultiple(int n1, int n2)
{
    if(0==n1%n2)
    {
        printf( "\n %d is a multiple of %d.\n", n1, n2 );
        return 1;
    }
    else
    {
        printf( "\n %d is Not a multiple of %d.\n", n1, n2 );
        return 0;
    }
}
//8- part1of2
int isprime(int N)
{
    int count=2;
    int i = 2;
    //Implementation
    while ( 0 != N%i && i <= sqrt(N))
    {
        i++;
        count=i;
    }
    if (0==N%count && 2!=N)
    {
        printf("\n %d is not a prime number", N);
        return 0;
    }
    else
    {
        printf("\n %d is a prime number", N);
        return 1;
    }
}
//8- part2of2
int getPrimesInInterval(int n1, int n2)
{
    int arr[100]= {0}, j=0;
    for (int i=n1,j=0; i <= n2; i++)
    {
        if (isprime(i))
        {
            arr[j] = i;
            j++;
        }
    }
    return arr[j];
}
//9- swap
void swap(int *a,int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
//10-poster holes.
int countHoles(int n)
{

    int digit,oneHole=0,twoHole=0;
    //Implementation
    if (n == 0)
        return 1;
    while (n != 0)
    {
        digit=n%10;
        switch (digit)
        {
        case 0:
            oneHole++;
            break;
        case 4:
            oneHole++;
            break;
        case 6:
            oneHole++;
            break;
        case 9:
            oneHole++;
            break;
        case 8:
            twoHole++;
            break;
        default:
            break;
        }
        n = n / 10;
    }
    printf("\n the number of holes = %d \n", (oneHole+2*twoHole));
    return (oneHole+2*twoHole);
}
//11- function that returns 1 if the input number is a power of 2 and return 0 if the input number is power of 2.
int checkPower(int n)
{
    if (n == 0)
        return 0;
    while (n != 1) {
        if (n % 2 != 0)
        {
        printf("\n the input number is Not a power of 2 \n");
          return 0;
        }
        n = n / 2;
    }
    printf("\n the input number is a power of 2 \n");
    return 1;
}
//12- heater activation
int heatTime(int c)
{
    if ( c>=0 && c<30 )
    {
        printf("\n heating time = 7");
        return 7;
    }
    else if ( c>=30 && c<60 )
    {
        printf("\n heating time = 5");
        return 5;
    }
    else if ( c>=60 && c<90 )
    {
        printf("\n heating time = 3");
        return 3;
    }
    else if ( c>=90 && c<=100 )
    {
        printf("\n heating time = 1");
        return 1;
    }
    else
    {
        printf("\n Invalid Input");
        return 0;
    }
}
//13- add two floating numbers. Determine the integer floor of the sum.
int addTwo(float a, float b)
{
    int sum = a+b;
    printf("\n sum = %d \n",sum);
    return sum;
}
//14- calculate the Fibonacci series
int fibo(int n) {
   if(n == 0){
      return 0;
   } else if(n == 1) {
      return 1;
   } else {
      return (fibo(n-1) + fibo(n-2));
   }
}


int main()
{
    cube(3);
    is_alpha('$');
    ispositive(-30);
    calcul(4,0,'/');
    checkodd(5);
    getUpper('h');
    isMultiple(6,2);
    getPrimesInInterval(1,14);

    int x=3,y=4;
    printf("\n\n x=%d \, y=%d \n",x,y);
    swap(&x,&y);
    printf(" swapping done \n");
    printf(" x=%d \, y=%d \n",x,y);

    countHoles(18940);
    checkPower(16);
    heatTime(50);
    addTwo(1.1,3.05);
    fibo(21);
    printf("\n Fibonacci = %d \n",fibo(21));

    printf("\n\n");
    return 0;
}
