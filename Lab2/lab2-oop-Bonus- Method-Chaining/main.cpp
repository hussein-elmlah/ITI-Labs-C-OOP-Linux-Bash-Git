#include <iostream>

using namespace std;
//c + oop(c++)

class Complex{
    //data
    double real;
    double image;
    Complex* that = this;

    //Method
    public:
       Complex & setReal(double _real){
           real=_real;
           return *that;
       }
         Complex & setImage(double _image){
            image=_image;
             return *that;
       }
        double getReal(void){
           return real;
       }
        double getImage(void){
           return image;
       }
       void printComplex(void){
           cout <<real;
           if(image>0){
                cout<<"+"<<image<<"j"<<endl;
           }
           else if(image<0){
                cout<<image<<"j"<<endl;
           }
           //cond?state1:stat2;

       }

};//end class

int main()
{
    //int x=0;
    Complex c;
    Complex c1;
    Complex c2;
    Complex c3;
    Complex c4;
    c.setImage(10);
    c.setReal(20);
    c1.setImage(100).setReal(200);
    c3.setImage(5).setReal(5);
   // c.printComplex();
    return 0;
}
