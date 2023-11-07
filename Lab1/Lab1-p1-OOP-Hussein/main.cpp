#include <iostream>

using namespace std;

void swapByR(int &a, int &b);
void swapByA(int* a, int* b);
//void swapByV(int a, int b);

int main()
{
    int a=2, b=3;
    cout << "a=" << a << "  b=" << b << endl << endl;
    swapByR(a,b);
    cout << "a=" << a << "  b=" << b << endl << endl;
    swapByA(&a,&b);
    cout << "a=" << a << "  b=" << b << endl << endl;
    //swapByV(a,b);
    //cout << "a=" << a << "  b=" << b << endl << endl;
    return 0;
}

void swapByR(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void swapByA(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*
void swapByV(int a, int b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
*/
