#include <stdio.h>
#include <stdlib.h>
int main()
{
    //1- check sign
    int a;
    printf("Enter any integer number to check sign:");
    scanf("%d",&a);
    if(a>0)
    {
        printf("the number is Positive");
    }
    else if(0==a)
    {
        printf("the number is Zero");
    }
    else
    {
        printf("the number is Negative");
    }
    printf("\n\n");
    //2-check if even or odd
    int b;
    printf("Enter any integer number to check if even or odd:");
    scanf("%d",&b);
    if(0==b%2)
    {
        printf("the number is even");
    }
    else if(1==b%2)
    {
        printf("the number is odd");
    }
    else
    {
        printf("error");
    }
    printf("\n\n");
    //3- write a C Program to Find the Largest Number Among Three Numbers.
    printf("3- Find the Largest Number:- \n");
    int n1, n2, n3, max;
    printf("Enter any three integer numbers: ");
    scanf("%d %d %d", &n1, &n2, &n3);
    max = n1;
    if (max < n2)
    {
        max = n2;
    }
    if (max < n3)
    {
        max = n3;
    }
    printf("Maximum among %d, %d, and %d is: %d", n1, n2, n3, max);
    printf("\n\n");
    //4-check grade
    int c;
    printf("Enter your percentage to check grade:");
    scanf("%d",&c);
    if ( c>=0 && c<50 )
    {
        printf("\n fail");
    }
    else if ( c>=50 && c<65 )
    {
        printf("\n Pass");
    }
    else if ( c>=65 && c<75 )
    {
        printf("\n Good");
    }
    else if ( c>=75 && c<85 )
    {
        printf("\n Very Good");
    }
    else if ( c>=85 && c<=100 )
    {
        printf("\n Excellent");
    }
    else
    {
        printf("\n invalid input");
    }
    printf("\n\n");
    //5- simple calculator
    printf("5- simple calculator:- \n");
    int num1, num2, res;
    float res_div;
    char opr;
    printf("Enter any two integer numbers to make simple calculations: ");
    scanf("%d%d", &num1, &num2);
    printf("Enter an operand of ( + , - , * , / ): ");
    scanf(" %c", &opr);
    if(1)printf(" the operand choosed is %C",opr);
    switch(opr)
    {
    case '+':
        res = num1+num2;
        printf("\n Addition = %d", res);
        break;
    case '-':
        res = num1-num2;
        printf("\n Subtraction = %d", res);
        break;
    case '*':
        res = num1*num2;
        printf("\n Multiplication = %d", res);
        break;
    case '/':
        if(0==num2)
        {
            printf("\n \"zero division exception\" \n");
            break;
        }
        res_div = (float)num1/num2;
        printf("\n Division = %f \n\n", res_div);
        break;
    default:
        printf(" an invalid operand.");
    }
    printf("\n\n");

    return 0;
}
