#include <iostream>

using namespace std;

class Complex
{
private:
    int real;
    int imaginary;
public:
    friend Complex sub (Complex , Complex );
    void setReal (int r)
    {
        real = r;
    }
    void setImaginary (int i)
    {
        imaginary = i;
    }
    int getReal (void)
    {
        return real;
    }
    int getImaginary (void)
    {
        return imaginary;
    }


    void print (void)
    {
        cout<<endl<<real;
        if (imaginary>0)
        {
            cout<<"+"<<imaginary<<"J";
        }
        else
        {
            cout<<imaginary<<"J";
        }
    }

    Complex add (Complex c2)
    {
        Complex res;
        res.setReal( real + c2.real);
        res.setImaginary( imaginary + c2.imaginary);
        return res;
    }
    Complex sub (Complex c2)
    {
        Complex res;
        res.setReal( real - c2.real);
        res.setImaginary( imaginary - c2.imaginary);
        return res;
    }

};

void print (Complex c);
Complex add (Complex c1, Complex c2);
Complex sub (Complex c1, Complex c2);

int main()
{
    Complex c1, c2, c3, c4;
    c1.setReal(5);
    c1.setImaginary(5);
    c1.print();
    c2.setReal(3);
    c2.setImaginary(3);
    c2.print();
    c3 = c1.add(c2);
    c3.print();
    c4 = c1.sub(c2);
    c4.print();

    print(c1);
    return 0;
}


void print (Complex c)
{
    int real = c.getReal();
    int imaginary = c.getImaginary();
    cout<<endl<<real;
    if (imaginary>0)
    {
        cout<<"+"<<imaginary<<"J";
    }
    else
    {
        cout<<imaginary<<"J";
    }
}

Complex add (Complex c1, Complex c2)
{
    Complex res;
    res.setReal( c1.getReal() + c2.getReal());
    res.setImaginary( c1.getImaginary() + c2.getImaginary());
    return res;
}

Complex sub (Complex c1, Complex c2)
{
    Complex res;
    res.setReal( c1.real - c2.real);
    res.setImaginary( c1.imaginary - c2.imaginary);
    return res;
}
