#include <iostream>
#include <graphics.h>
#include <cstdio>


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
        //cout<<"constructor point"<<endl;
    }
    ~Point()
    {
        //cout<<"Destructor point"<<endl;
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

class Shape
{
private:
    int color;
public:
    Shape(int a=15)
    {
        color = a;
    }
    void setColor(int _color)
    {
        if(color >=0 && color <=15)
        {
            color = _color;
        }
    }
    int getcolor()
    {
        return color;
    }
    virtual void display()//method will be overridden in driven classes.
    {
        setcolor(color);//setcolor of grahphics.h lib.
        cout<<endl<<"Just Shape"<<endl;
    }
    virtual void input()//method will be overridden in driven classes.
    {
        cout<<endl<<"input Shape"<<endl;
    }
};//End of class Shape.

class Circle : public Shape
{
private:
    Point p;
    Point *ptr;
    int radius;
public:
    Circle():p(0,0),Shape(15)
    {
        radius = 0;
        ptr = &p;
    }
    //why adding reference & to these parameters make a problem ?
    Circle(int px, int py, int rad) //Composition
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
        //cout<<"destructor circle OOO destructor OOO"<<endl;
    }
    void setCircle(int a, int b, int c)
    {
        p.setPoint(a,b);
        radius = c;
    }
    void display()
    {
        setcolor(getcolor());//setcolor of grahphics.h lib.
        circle(p.getX(),p.getY(), radius);
        //cout<<endl<<"OOO( Circle_displayed )-coordinates->"<<p.getX()<<"-"<<p.getY()<<"-"<<radius<<" . OOO"<<endl<<endl;
    }
    void input()
    {
        int a,b,c,d;
        cout << "(Enter circle values)"<<endl;
        cout << "Enter center-point x-value ";
        cin >> a;
        cout << "Enter center-point y-value ";
        cin >> b;
        cout << "Enter radius ";
        cin >> c;
        cout << "Enter shape color between 1 to 15 : ";
        cin >> d;
        setCircle(a,b,c);
        setColor(d);
    }
};//End of class Circle.

class Line : public Shape
{
private:
    Point p1,p2;//composition
    Point *ptr1, *ptr2;
public:
    Line():p1(0,0),p2(0,0)
    {
        //cout<<"default constructor line --------constructor--------"<<endl;
        ptr1 = &p1;
        ptr2 = &p2;
        //Why default constructor line doesn't work ?
        //I need to study overloading more.
    }
    Line(int x1, int y1, int x2, int y2):p1(x1,y1),p2(x2,y2)//Composition
    {
        ptr1 = &p1;
        ptr2 = &p2;
        //cout<<"constructor line by 4 ints --------constructor--------"<<endl;
    }
    Line(Point &_p1, Point &_p2)//  ////debate for using p1,p2,ptr1,ptr2 ?
    {
        p1=_p1;
        p2=_p2;
        ptr1 = &p1;
        ptr2 = &p2;
        //cout<<"constructor line --------constructor--------"<<endl;
    }
    Line(Point *_p1, Point *_p2)//Aggregation////
    {
        ptr1 = _p1;
        ptr2 = _p2;
        //cout<<"constructor line --------constructor--------"<<endl;
    }
    ~Line()
    {
        //cout<<"destructor line --------destructor--------"<<endl;
    }
    void setPoints(int x1, int y1, int x2, int y2)//Composition
    {
        p1.setPoint(x1,y1);
        p2.setPoint(x2,y2);
        //cout<<"constructor line by 4 ints --------constructor--------"<<endl;
    }
    void setPoints (Point *_p1, Point *_p2)//aggregation
    {
        ptr1=_p1;
        ptr2=_p2;
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
    void setLine(int a, int b, int c, int d)
    {
        p1.setPoint(a,b);
        p2.setPoint(c,d);
    }
    void display()
    {
        if(ptr1 != NULL && ptr2 != NULL)
        {
            setcolor(getcolor());//setcolor of grahphics.h lib.
            line(ptr1->getX(),ptr1->getY(),ptr2->getX(),ptr2->getY());
            //cout<<endl<<"___( Line_displayed )-coordinates->"<<p1.getX()<<"-"<<p1.getY()<<"-"<<p2.getX()<<"-"<<p2.getY()<<" . ___"<<endl<<endl;
        }
        else
        {
            cout<<endl<<"null ptr in points ptrs."<<endl;
        }
    }
    void input()
    {
        int a,b,c,d,e;
        cout << "(Enter line values)"<<endl;
        cout << "Enter point1 x-value ";
        cin >> a;
        cout << "Enter point1 y-value ";
        cin >> b;
        cout << "Enter point2 x-value ";
        cin >> c;
        cout << "Enter point2 y-value ";
        cin >> d;
        cout << "Enter shape color between 1 to 15 : ";
        cin >> e;
        setLine(a,b,c,d);
        setColor(e);
    }
};//End of class Line.


class Rect : public Shape
{
    Point p1,p2;
    Point *ptr1, *ptr2;
public:
    Rect():p1(0,0),p2(0,0)
    {
        //cout<<"default constructor Rectangle --------constructor--------"<<endl;
        ptr1 = &p1;
        ptr2 = &p2;
        //Why default constructor Rectangle doesn't work ?
        //I need to study overloading more.
    }
    Rect(int x1, int y1, int x2, int y2):p1(x1,y1),p2(x2,y2)//Composition
    {
        ptr1 = &p1;
        ptr2 = &p2;
        //cout<<"constructor Rectangle by 4 ints --------constructor--------"<<endl;
    }
    Rect(Point &_p1, Point &_p2)//  ////debate for using p1,p2,ptr1,ptr2 ?
    {
        p1=_p1;
        p2=_p2;
        ptr1 = &p1;
        ptr2 = &p2;
        //cout<<"constructor Rectangle --------constructor--------"<<endl;
    }
    Rect(Point *_p1, Point *_p2)//Aggregation////
    {
        ptr1 = _p1;
        ptr2 = _p2;
        //cout<<"constructor Rectangle --------constructor--------"<<endl;
    }
    ~Rect()
    {
        //cout<<"destructor Rectangle --------destructor--------"<<endl;
    }
    void setPoints(int x1, int y1, int x2, int y2)//Composition
    {
        p1.setPoint(x1,y1);
        p2.setPoint(x2,y2);
        //cout<<"constructor Rectangle by 4 ints --------constructor--------"<<endl;
    }
    void setPoints (Point *_p1, Point *_p2)//aggregation
    {
        ptr1=_p1;
        ptr2=_p2;
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
    void setRect(int a, int b, int c, int d)
    {
        p1.setPoint(a,b);
        p2.setPoint(c,d);
    }
    void display()
    {
        setcolor(getcolor());//setcolor of grahphics.h lib.
        if(ptr1 != NULL && ptr2 != NULL)
        {
            rectangle(ptr1->getX(),ptr1->getY(),ptr2->getX(),ptr2->getY());
            //cout<<endl<<"___( Rectangle_displayed )-coordinates->"<<p1.getX()<<"-"<<p1.getY()<<"-"<<p2.getX()<<"-"<<p2.getY()<<" . ___"<<endl<<endl;
        }
        else
        {
            cout<<endl<<"null ptr in points ptrs."<<endl;
        }
    }
    void input()
    {
        int a,b,c,d,e;
        cout << "(Enter Rectangle values)"<<endl;
        cout << "Enter point1 x-value ";
        cin >> a;
        cout << "Enter point1 y-value ";
        cin >> b;
        cout << "Enter point2 x-value ";
        cin >> c;
        cout << "Enter point2 y-value ";
        cin >> d;
        cout << "Enter shape color between 1 to 15 : ";
        cin >> e;
        setRect(a,b,c,d);
        setColor(e);
    }
};//End of class Rectangle.




int main()
{
    int gd=DETECT, gm;
    initgraph (&gd, &gm, (char*)"");
    //=================================================
    int nShapes=0,shapeType=0;
    cout<<endl<<"Enter number of shapes (from 1 to 10) : ";
    cin >> nShapes;
    Shape** shapes = new Shape*[nShapes];
    for(int i=0;i<nShapes;i++)
    {
        fflush(stdin);//why crashing happens not input handling ??
        cout<<endl<<"Enter type of shape "<<i+1<<" : (1:circle,2:line,3:rectangle) : ";
        cin>>shapeType;
        if(1==shapeType)
        {
            shapes[i]=new Circle;
        }
        else if(2==shapeType)
        {
            shapes[i]=new Line;
        }
        else if(3==shapeType)
        {
            shapes[i]=new Rect;
        }
        else
        {
            i--;
            cout<<"invalid input.";
        }
    }
    cout<<endl<<"Types entered successfully."<<endl<<endl;


    for(int i=0; i<nShapes; i++)
    {
        shapes[i]->input();
    }
    cout<<endl<<"Shapes entered successfully."<<endl<<endl;

    for(int i=0; i<nShapes; i++)
    {
        shapes[i]->display();
    }
    cout<<endl<<"Shapes displayed successfully."<<endl<<endl;


    /*
    Circle c1(500,120,70);
    Circle c2(400,100,50);
    Line l1(10,11,120,130);
    Rect r1(200,11,320,130);
    c1.setColor(14);
    l1.setColor(13);
    r1.setColor(12);
    c1.display();
    c1.setColor(12);
    c2.display();
    l1.display();
    r1.display();
    */

    getch() ;
    closegraph() ;
    //memory deallocation.
    delete []shapes;
    return 0;
}

