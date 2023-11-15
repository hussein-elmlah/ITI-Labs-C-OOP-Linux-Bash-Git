#include <iostream>
#include <graphics.h>
#include <cstdio>


using namespace std;
class Circle;
class Line;
class Rect;

class Point
{
private:
    int x,y;
public:
    friend istream & operator >> (istream &in,  Circle &a);
    friend istream & operator >> (istream &in,  Line &a);
    friend istream & operator >> (istream &in,  Rect &a);
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

class Shape
{
private:
    int color;
public:
    friend istream & operator >> (istream &in,  Circle &a);
    friend istream & operator >> (istream &in,  Line &a);
    friend istream & operator >> (istream &in,  Rect &a);
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
    void display()//method will be overridden in driven classes.
    {
        setcolor(color);//setcolor of grahphics.h lib.
        cout<<endl<<"Just Shape"<<endl;
    }
};//End of class Shape.

class Circle : public Shape
{
private:
    Point p;
    Point *ptr;
    int radius;
public:
    friend istream & operator >> (istream &in,  Circle &c);
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
        cout<<"destructor circle OOO destructor OOO"<<endl;
    }
    void display()
    {
        setcolor(getcolor());//setcolor of grahphics.h lib.
        circle(p.getX(),p.getY(), radius);
        cout<<endl<<"OOO( Circle_displayed )-coordinates->"<<p.getX()<<"-"<<p.getY()<<"-"<<radius<<" . OOO"<<endl<<endl;
    }
};//End of class Circle.

class Line : public Shape
{
private:
    Point p1,p2;//composition
    Point *ptr1, *ptr2;
public:
    friend istream & operator >> (istream &in,  Line &a);
    Line():p1(0,0),p2(0,0)
    {
        cout<<"default constructor line --------constructor--------"<<endl;
        ptr1 = &p1;
        ptr2 = &p2;
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
            setcolor(getcolor());//setcolor of grahphics.h lib.
            line(ptr1->getX(),ptr1->getY(),ptr2->getX(),ptr2->getY());
            cout<<endl<<"___( Line_displayed )-coordinates->"<<p1.getX()<<"-"<<p1.getY()<<"-"<<p2.getX()<<"-"<<p2.getY()<<" . ___"<<endl<<endl;
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


class Rect : public Shape
{
    Point p1,p2;
    Point *ptr1, *ptr2;
public:
    friend istream & operator >> (istream &in,  Rect &a);
    Rect():p1(0,0),p2(0,0)
    {
        cout<<"default constructor Rectangle --------constructor--------"<<endl;
        ptr1 = &p1;
        ptr2 = &p2;
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
        setcolor(getcolor());//setcolor of grahphics.h lib.
        if(ptr1 != NULL && ptr2 != NULL)
        {
            rectangle(ptr1->getX(),ptr1->getY(),ptr2->getX(),ptr2->getY());
            cout<<endl<<"___( Rectangle_displayed )-coordinates->"<<p1.getX()<<"-"<<p1.getY()<<"-"<<p2.getX()<<"-"<<p2.getY()<<" . ___"<<endl<<endl;
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




int main()
{
    int gd=DETECT, gm;
    initgraph (&gd, &gm, (char*)"");
    //=================================================
    int nShapes=0, circlesCount=0, linesCount=0, rectsCount=0, circlesCounter=0, linesCounter=0, rectsCounter=0;
    cout<<endl<<"Enter number of shapes (from 1 to 10) : ";
    cin >> nShapes;
    int* shapes = new int[nShapes];
    for(int i=0; i<nShapes; i++)
    {
        fflush(stdin);//why crashing happens not input handling ??
        cout<<endl<<"Enter type of shape "<<i+1<<" : (1:circle,2:line,3:rectangle) : ";
        cin>>shapes[i];
        if(1==shapes[i])
        {
            circlesCount++;
        }
        else if(2==shapes[i])
        {
            linesCount++;
        }
        else if(3==shapes[i])
        {
            rectsCount++;
        }
        else
        {
            i--;
            cout<<"invalid input.";
        }
    }
    cout<<endl<<"Shapes entered successfully."<<endl<<endl;
    Circle* circles = new Circle[circlesCount];
    Line* lines = new Line[linesCount];
    Rect* rects = new Rect[rectsCount];

    for(int i=0; i<nShapes; i++)
    {
        if(1==shapes[i])
        {
            cin>>circles[circlesCounter];
            circlesCounter++;
        }
        else if(2==shapes[i])
        {
            cin>>lines[linesCounter];
            linesCounter++;
        }
        else if(3==shapes[i])
        {
            cin>>rects[rectsCounter];
            rectsCounter++;
        }
        else
        {
            cout<<endl<<"error."<<endl;
        }
    }

    for(int i=0; i<circlesCount; i++)
    {
        circles[i].display();
    }
    for(int i=0; i<linesCount; i++)
    {
        lines[i].display();
    }
    for(int i=0; i<rectsCount; i++)
    {
        rects[i].display();
    }


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
    delete []circles;
    delete []lines;
    delete []rects;
    return 0;
}

istream & operator >> (istream &in,  Circle &a)
{
    cout << "(Enter circle values)"<<endl;
    cout << "Enter center-point x-value ";
    in >> a.p.x;
    cout << "Enter center-point y-value ";
    in >> a.p.y;
    cout << "Enter radius ";
    in >> a.radius;
    cout << "Enter shape color between 1 to 15 : ";
    in >> a.color;
    return in;
}
istream & operator >> (istream &in,  Line &a)
{
    cout << "(Enter line values)"<<endl;
    cout << "Enter point1 x-value ";
    in >> a.p1.x;
    cout << "Enter point1 y-value ";
    in >> a.p1.y;
    cout << "Enter point2 x-value ";
    in >> a.p2.x;
    cout << "Enter point2 y-value ";
    in >> a.p2.y;
    cout << "Enter shape color between 1 to 15 : ";
    in >> a.color;
    return in;
}
istream & operator >> (istream &in,  Rect &a)
{
    cout << "(Enter rectangle values)"<<endl;
    cout << "Enter point1 x-value ";
    in >> a.p1.x;
    cout << "Enter point1 y-value ";
    in >> a.p1.y;
    cout << "Enter point2 x-value ";
    in >> a.p2.x;
    cout << "Enter point2 y-value ";
    in >> a.p2.y;
    cout << "Enter shape color between 1 to 15 : ";
    in >> a.color;
    return in;
}

