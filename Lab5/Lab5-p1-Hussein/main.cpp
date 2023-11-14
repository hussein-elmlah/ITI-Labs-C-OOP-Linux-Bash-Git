#include <iostream>
#include <graphics.h>

using namespace std;

class Point
{
private:
    int x,y;
public:
    Point(int a=0, int b=0)
    {
        x=a;
        y=b;
        cout<<"constructor point"<<endl;
    }
    ~Point()
    {
        cout<<"Destructor point"<<endl;
    }
    void setX(int a)
    {
        x=a;
    }
    void setY(int b)
    {
        y=b;
    }
    void setPoint(int a, int b)
    {
        x=a;
        y=b;
    }
    int getX(void)
    {
        return x;
    }
    int getY(void)
    {
        return y;
    }
    Point getPoint(void)
    {
        return *this;
    }
    void print(void)
    {
        cout<<"("<<x<<","<<y<<")"<<endl;
    }

    Point &operator = (Point &p)
    {
        x = p.x;
        y = p.y;
        return *this;
    }
};//End of class Point.

class Line
{
private:
    Point p1,p2;//composition
    Point *ptr1, *ptr2;
public:
    Line():p1(0,0),p2(0,0)
    {
        cout<<"default constructor line --------constructor--------"<<endl;
        ptr1 = NULL;
        ptr2 = NULL;
        //Why default constructor line doesn't work ?
        //I need to study overloading more.
    }
    Line(int x1, int y1, int x2, int y2):p1(x1,y1),p2(x2,y2)//Composition
    {
        ptr1 = &p1;
        ptr2 = &p2;
        cout<<"constructor line by 4 ints --------constructor--------"<<endl;
    }
    Line(Point &_p1, Point &_p2)//  ////debate for using p1,p2,ptr1,ptr2 ?
    {
        p1=_p1;
        p2=_p2;
        ptr1 = &p1;
        ptr2 = &p2;
        cout<<"constructor line --------constructor--------"<<endl;
    }
    Line(Point *_p1, Point *_p2)//Aggregation////
    {
        ptr1 = _p1;
        ptr2 = _p2;
        cout<<"constructor line --------constructor--------"<<endl;
    }
    ~Line()
    {
        cout<<"destructor line --------destructor--------"<<endl;
    }
    void setPoints(int x1, int y1, int x2, int y2)//Composition
    {
        p1.setPoint(x1,y1);
        p2.setPoint(x2,y2);
        cout<<"constructor line by 4 ints --------constructor--------"<<endl;
    }
    void setPoints (Point *_p1, Point *_p2)//aggregation
    {
        ptr1=_p1;
        ptr2=_p2;
    }
    void display()
    {
        if(ptr1 != NULL && ptr2 != NULL)
        {
        line(ptr1->getX(),ptr1->getY(),ptr2->getX(),ptr2->getY());
        cout<<endl<<"________( Line_displayed )-coordinates->"<<p1.getX()<<"-"<<p1.getY()<<"-"<<p2.getX()<<"-"<<p2.getY()<<" . ________"<<endl<<endl;
        }
        else
        {
            cout<<endl<<"null ptr in points ptrs."<<endl;
        }
    }
    void printPoints(Point p1,Point p2) //assoication
    {
        p1.print();
        p2.print();
    }
    void printPoints() //aggregation
    {
        if(ptr1 != NULL && ptr2 != NULL)
        {
            ptr1->print();
            ptr2->print();
        }
        else
        {
            cout<<endl<<"null ptr in points ptrs."<<endl;
        }
    }
    void removePoints(void)
    {
        ptr1 = NULL;
        ptr2 = NULL;
    }
};//End of class Line.


class Rect
{
    Point p1,p2;
    Point *ptr1, *ptr2;
public:
    Rect():p1(0,0),p2(0,0)
    {
        cout<<"default constructor Rectangle --------constructor--------"<<endl;
        ptr1 = NULL;
        ptr2 = NULL;
        //Why default constructor Rectangle doesn't work ?
        //I need to study overloading more.
    }
    Rect(int x1, int y1, int x2, int y2):p1(x1,y1),p2(x2,y2)//Composition
    {
        ptr1 = &p1;
        ptr2 = &p2;
        cout<<"constructor Rectangle by 4 ints --------constructor--------"<<endl;
    }
    Rect(Point &_p1, Point &_p2)//  ////debate for using p1,p2,ptr1,ptr2 ?
    {
        p1=_p1;
        p2=_p2;
        ptr1 = &p1;
        ptr2 = &p2;
        cout<<"constructor Rectangle --------constructor--------"<<endl;
    }
    Rect(Point *_p1, Point *_p2)//Aggregation////
    {
        ptr1 = _p1;
        ptr2 = _p2;
        cout<<"constructor Rectangle --------constructor--------"<<endl;
    }
    ~Rect()
    {
        cout<<"destructor Rectangle --------destructor--------"<<endl;
    }
    void setPoints(int x1, int y1, int x2, int y2)//Composition
    {
        p1.setPoint(x1,y1);
        p2.setPoint(x2,y2);
        cout<<"constructor Rectangle by 4 ints --------constructor--------"<<endl;
    }
    void setPoints (Point *_p1, Point *_p2)//aggregation
    {
        ptr1=_p1;
        ptr2=_p2;
    }
    void display()
    {
        if(ptr1 != NULL && ptr2 != NULL)
        {
        rectangle(ptr1->getX(),ptr1->getY(),ptr2->getX(),ptr2->getY());
        cout<<endl<<"________( Line_displayed )-coordinates->"<<p1.getX()<<"-"<<p1.getY()<<"-"<<p2.getX()<<"-"<<p2.getY()<<" . ________"<<endl<<endl;
        }
        else
        {
            cout<<endl<<"null ptr in points ptrs."<<endl;
        }
    }
    void printPoints(Point p1,Point p2) //assoication
    {
        p1.print();
        p2.print();
    }
    void printPoints() //aggregation
    {
        if(ptr1 != NULL && ptr2 != NULL)
        {
            ptr1->print();
            ptr2->print();
        }
        else
        {
            cout<<endl<<"null ptr in points ptrs."<<endl;
        }
    }
    void removePoints(void)
    {
        ptr1 = NULL;
        ptr2 = NULL;
    }
};//End of class Rectangle.

class Circle
{
private:
    Point p;
    Point *ptr;
    int radius;
public:
    Circle():p(0,0)
    {
        radius = 0;
        ptr = &p;
    }
    //why adding reference & to these parameters make a problem ?
    Circle(int px, int py , int rad)//Composition
    {
        p.setPoint(px,py);
        radius = rad;
        ptr = &p;
    }
    Circle(Point _p, int rad)//Assosiation
    {
        p = _p;
        ptr = &p;
        radius = rad;
    }
    Circle(Point *_p, int rad)//Aggregation
    {
        ptr = _p;
        radius = rad;
    }
    ~Circle()
    {
        cout<<"destructor circle OOO destructor OOO"<<endl;
    }
    void display(){
	    circle(p.getX(),p.getY(), radius);
	    cout<<endl<<"OOO( Circle_displayed )-coordinates->"<<p.getX()<<"-"<<p.getY()<<"-"<<radius<<" . OOO"<<endl<<endl;
	}
};//End of class Circle.


int main()
{
    int gd=DETECT, gm;
    initgraph (&gd, &gm, (char*)"");
    //=================================================
    /*
    Point p1(2,3), p2;
    Line l0(p1,p2);
    Line l2();//Why default constructor line doesn't work ?
    Line l3(1,2,3,4);
    */
    //=================================================
    Line l2;

    Rect r1(200,11,320,130);
    r1.display();
    Line l1(10,11,120,130);
    l1.display();
    Circle c1(500,120,70);
    c1.display();


    //=================================================


    getch() ;
    closegraph() ;
    return 0;
}
