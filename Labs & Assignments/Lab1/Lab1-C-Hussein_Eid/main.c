#include <stdio.h>
#include <stdlib.h>
int main()
{
    printf("Welcome to program!\n\n");
    //1- install the C environment.
    printf("1- the C environment installed!\n\n");
    //2- write a C Program to test different format Specifiers with "Printf".
    char a = 'A'; signed int b = -5; unsigned int c = 5; float d = 7.5; double e = 999;
    printf("2- format specifiers: char %c  signed int %d  unsigned int %i  float %f  double %lf \n\n",a,b,c,d,e);
    //3- write a C Program to print ASCII number of a given char.
    char f = 'A';
    printf("3- ASCII of %c is %i \n\n",f,f);
    //4- write a C Program to add two integers.
    unsigned int  g = 6, h = 7;
    unsigned int i = g+h;
    printf("4- Adding %i to %i equal %i \n\n",g,h,i);
    //5- write a C Program to print Hexa of a number.
    unsigned j = 8888;
    printf("5- the Hexa of %i is %x \n\n",j,j);

    //6- write a C Program to make simple calculations (add, sub, multiply, divide) on two integers
    printf("6- simple calculations:- \n");
    int num1, num2, res; float res_div;
    printf("Enter any two integer numbers to make simple calculations: ");
    scanf("%d%d", &num1, &num2);
    res = num1+num2;
    printf("\n Addition = %d", res);
    res = num1-num2;
    printf("\n Subtraction = %d", res);
    res = num1*num2;
    printf("\n Multiplication = %d", res);
    res_div = (float)num1/num2;
    printf("\n Division = %f \n\n", res_div);

    //7- write a C Program to compute Quotient and Remainder.
    printf("7- Quotient and Remainder:- \n");
    int num3, num4, q, r;
    printf("Enter any two integer numbers to compute Quotient and Remainder: ");
    scanf("%d%d", &num3, &num4);
    q = num3/num4;
    r = num3%num4;
    printf("\n quotient = %d & remainder = %d \n\n",q,r);

    //8- write a C Program to Find the Largest Number Among Three Numbers.
    printf("8- Find the Largest Number:- \n");
    int n1, n2, n3, max;
    printf("Enter any three integer numbers: ");
    scanf("%d %d %d", &n1, &n2, &n3);
    max = n1;
    if (max < n2) max = n2;
    if (max < n3) max = n3;
    printf("Maximum among %d, %d, and %d is: %d \n\n", n1, n2, n3, max);

    return 0;
}
