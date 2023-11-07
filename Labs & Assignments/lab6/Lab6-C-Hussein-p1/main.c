#include <stdio.h>
#include <stdlib.h>

void swap(int* x, int* y);

int main()
{
    //Swapping using 3 Methods.
    //Method1
    int x=1, y=2;
    printf("\n Before swapping X = %d and Y = %d \n", x, y);
    swap(&x, &y);
    printf("\n After swapping X = %d and Y = %d \n", x, y);
    //Method2
    int a=1 , b=2;
    printf("\n Before swapping A = %d and B = %d \n", a, b);
    a = a + b;
    b = a - b;
    a = a - b;
    printf("\n After swapping A = %d and B = %d \n", a, b);
    //Method3
    int c=1 , d=2;
    printf("\n Before swapping C = %d and D = %d \n", c, d);
    c = c * d;
    d = c / d;
    c = c / d;
    printf("\n After swapping C = %d and D = %d \n", c, d);

    printf("\n\n");
    return 0;
}

void swap(int* x, int* y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
