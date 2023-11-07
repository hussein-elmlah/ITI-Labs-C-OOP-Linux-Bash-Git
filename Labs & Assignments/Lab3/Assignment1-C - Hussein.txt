#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

    /*
    //1-Equation program which Result = ((num1 + num2) * 3) - 10 .
    int firstInput, secondInput = 0;
    int num1, num2, res;
    printf(" Enter two integer numbers:\n");
    //firstInput
    do
    {
        fflush(stdin);
        printf(" Enter first number:");
        firstInput = scanf("%d", &num1);
    }
    while( 0 == firstInput );
    //secondInput
    do
    {
        fflush(stdin);
        printf(" Enter second number:");
        secondInput = scanf("%d", &num2);
    }
    while( 0 == secondInput );
    //implementation
    res = (((num1 + num2) * 3) - 10) ;
    printf("\n Result = ((num1 + num2) * 3) - 10 = %d \n\n", res);
    */

    //2- print your name and your grade
    printf("\n My name: Hussein Eid Ismael \n My grade: Excellent \n");


    /*
    //3- converting temperature from degrees Celsius to degrees Fahrenheit
    int firstInput = 0;
    int a, b;
    //firstInput
        do
    {
        fflush(stdin);
        printf("1- Enter Celsius degree:");
        firstInput = scanf("%d", &a);
    }
    while( 0 == firstInput);
    //Implementation
    b = ((a * (float)9/5) + 32) ;
    printf("\n degrees in Fahrenheit = ((C * 9/5) + 32) = %d \n", b);
    */

    /*
    //4- a circle area and circumference calculations
    int firstInput = 0;
    float rad, area, circ;
    //firstInput
    do
    {
        fflush(stdin);
        printf("Please Enter a positive integer number:");
        firstInput = scanf("%f", &rad);
    }
    while(rad<0 || firstInput == 0);
    //Implementation
    area = ((float)22/7)*rad*rad ;
    circ = 2*((float)22/7)*rad ;
    printf("\n area = %f \n circumference = %f \n", area, circ);
    */

    /*
    //5- print the ASCII value of a character
    char ch;
    printf("Enter a character: ");
    scanf("%c",&ch);
    printf("\n The ascii value of the %c variable is : %d", ch, ch);
    */

    /*
    //6- relation between two integer number
    int firstInput, secondInput = 0;
    int a, b;
    //firstInput
    do
    {
        fflush(stdin);
        printf("Enter the first integer: ");
        firstInput = scanf("%d", &a);
    }
    while( 0 == firstInput );
    //secondInput
    do
    {
        fflush(stdin);
        printf("Enter the second integer: ");
        secondInput = scanf("%d", &b);
    }
    while( 0 == secondInput );
    //Implementation
    if (a == b)
    {
        printf("Equal\n");
    }
    else
    {
        printf("Not equal\n");
    }
    if (a > b)
    {
        printf("The first number is higher value");
    }
    else
    {
        printf("The second number is higher value");
    }
    */


    /*
    //7-the smallest number.
    int firstInput, secondInput, thirdInput = 0;
    int a, b, c, small;
    printf("Enter three numbers :- \n");
    //firstInput
    do
    {
        fflush(stdin);
        printf("Enter the first integer: ");
        firstInput = scanf("%d", &a);
    }
    while( 0 == firstInput );
    //secondInput
    do
    {
        fflush(stdin);
        printf("Enter the second integer: ");
        secondInput = scanf("%d", &b);
    }
    while( 0 == secondInput );
    //thirdInput
    do
    {
        fflush(stdin);
        printf("Enter the third integer: ");
        thirdInput = scanf("%d", &c);
    }
    while( 0 == thirdInput );
    //Implementation
    if(a<b && a<c)
    {
        small = a;
    }
    else if(b<a && b<c)
    {
        small = b;
    }
    else
    {
        small = c;
    }
    printf("\nSmallest number is: %d \n", small);
    */

    /*
    //8-checks if it is a perfect square
    int firstInput = 0;
    int num;
    int iVar;
    float fVar;
    //firstInput
    do
    {
        fflush(stdin);
        printf("Please Enter a positive integer number:");
        firstInput = scanf("%d",&num);
    }
    while( 0 == firstInput || num < 0 );
    //Implementation
    fVar=sqrt((double)num);
    iVar=fVar;
    if(iVar==fVar)
    {
        printf("%d is a perfect square.\n",num);
    }
    else
    {
        printf("%d is not a perfect square.\n",num);
    }
    */

    /*
    //9-check grade
    int firstInput = 0;
    int c;
    //firstInput
    do
    {
        fflush(stdin);
        printf("Enter your percentage to check grade:");
        firstInput = scanf("%d",&c);
    }
    while( 0 == firstInput || c<0 || c>100 );
    //Implementation
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
        printf("\n Error");
    }
    printf("\n\n");
    */

    /*
    //10- simple calculator
    printf(" simple calculator:- \n");
    int firstInput, secondInput, thirdInput, goodOpr = 0;
    int num1, num2, res;
    float res_div;
    char opr;
    printf("Enter any two integer numbers to make simple calculations:- \n");
    //firstInput
    do
    {
        fflush(stdin);
        printf("Enter first number:");
        firstInput = scanf("%d", &num1);
    }
    while( 0 == firstInput );
    //secondInput
    do
    {
        fflush(stdin);
        printf("Enter second number:");
        secondInput = scanf("%d", &num2);
    }
    while( 0 == secondInput );
    //thirdInput
    do
    {
        fflush(stdin);
        printf("Enter an operand of ( + , - , * , / ): ");
        thirdInput = scanf(" %c", &opr);
        if('+'==opr || '-'==opr || '*'==opr || '/'==opr)
        {
            goodOpr = 1 ;
        }
    }
    while( 0 == thirdInput || 1 != goodOpr  );
    //Implementation
    printf(" the operand choosed is %C",opr);
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
    */

    /*
    //11-Print sum of first 100 integers. (With data validation)
    int goodInput = 0;
    int sum = 0;
    int arr[100]= {};
    //get input
    for (int i=0; i<100; i++)
    {

        do
        {
            fflush(stdin);
            printf(" Enter element number %d :",i+1);
            goodInput = scanf("%d",&arr[i]);
        }
        while( 0 == goodInput );
    }
    //Implementation
    for (int i=0; i<100; i++)
    {
        sum += arr[i];
    }
    printf("\n Sum of the first 100 integer = %d \n\n", sum);
    */

    /*
    //12-computes the factorial.
    int firstInput = 0;
    int a, fact = 1;
    //firstInput
    do
    {
        fflush(stdin);
        printf("1- Enter the number to get factorial:");
        firstInput = scanf("%d", &a);
    }
    while( 0 == firstInput || a<1);
    //Implementation
    for (int i=a; i>0; i--){
        fact *= i;
    }
    printf("\n the factorial = %d \n\n", fact);
    */


    /*
    //13- checks if it is a prime.
    int firstInput = 0;
    int N=1,count=2;
    int i = 2;
    //firstInput
    do
    {
        fflush(stdin);
        printf("1- Enter the number to get check if a prime:");
        firstInput = scanf("%d", &N);
    }
    while( 0 == firstInput || N<1);
    //Implementation
    while ( 0 != N%i && i <= sqrt(N)){
        i++;
        count=i;
    }
    if (0==N%count && 2!=N) {
        printf("%d is not a prime number", N);

    }
    else {
        printf("%d is a prime number", N);
    }
    */

    /*
    //14- English alphabets
    printf("\n English alphabets:\n");
    for(int i=65; i<=90; i++){
        printf(" %c", i);
    }
    */

    /*
    //15- calculate the power of a number.
    int firstInput, secondInput = 0;
    int num1, num2;
    float res=1;
    printf("\n Enter a number and his power to calc:\n");
    //firstInput
    do
    {
        fflush(stdin);
        printf(" Enter the number:");
        firstInput = scanf("%d", &num1);
    }
    while( 0 == firstInput );
    //secondInput
    do
    {
        fflush(stdin);
        printf(" Enter the power:");
        secondInput = scanf("%d", &num2);
    }
    while( 0 == secondInput );
    //implementation
    if(num2>0)
    {
        for(int i=0; i<num2; i++)
        {
            res *= num1;
        }
    }
    else if(num2<0)
    {
        for(int i=0; i<(-num2); i++)
        {
            res *= num1;
        }
        res=(float)1/res;
    }
    printf("\n the result = %f \n", res);
    */

    /*
    //16- reverse a number
    int firstInput = 0;
    int number, rev = 0, remainder;
    //firstInput
    do
    {
        fflush(stdin);
        printf("\nEnter any integer number: ");
        firstInput = scanf("%d",&number);
    }
    while( 0 == firstInput );
    //Implementation
    while(number != 0)
    {
        remainder = number%10;
        rev = rev*10 + remainder;
        number /= 10;
    }
    printf("\nReversed Number: %d \n",rev);
    */

    /*
    //17- count number of digits in a decimal number.
    int firstInput = 0;
    int num, count = 0;
    //firstInput
    do
    {
        fflush(stdin);
        printf("\nEnter any integer number: ");
        firstInput = scanf("%d",&num);
    }
    while( 0 == firstInput );
    //Implementation
    if (num == 0)
        count = 1;
    while (num != 0)
    {
        num = num / 10;
        ++count;
    }
    printf("\n Number of digits : %d \n", count);
    */

    /*
    //18- Write a program to display half pyramid using stars pattern.
    int rows = 5;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            printf("* ");
        }
        printf("\n");
    }
    */

    /*
    //19- Write a program to display inverted half pyramid using stars pattern.
    int rows = 5;
    for (int i = 0; i < rows; i++)
    {
        for (int j = rows; j > i; j--)
        {
            printf("* ");
        }
        printf("\n");
    }
    */

    /*
    //20- Write a program to display a full pyramid using stars pattern.
    int rows = 5;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < (rows-i)-1; j++)
        {
            printf(" ");
        }
        for (int k = 0; k < (2*i)+1; k++)
        {
            printf("*");
        }
        printf("\n");
    }
    */

    /*
    //21- Write a program to display cross or X-shape using stars pattern.
    int n=10;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i==j || j==(n-i-1))
            {
                printf(" *");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    */


    printf("\n\n");
    return 0;
}
