#include <iostream>

using namespace std;

template < class T>

class Stack
{
private:
    T* arr;
    int arrSize;
    int top;
public:
    Stack(int arraySize)
    {
        cout<<"constructor"<<endl;
        arrSize = arraySize;
        arr = new T[arrSize] {0};
        top = -1;
    }
    void extend(void)
    {
        T* ptrTemp = new T[2*arrSize] {0};
        for(int i=0; i<arrSize; i++)
        {
            ptrTemp[i]=arr[i];
        }
        delete [] arr;
        arr = ptrTemp;
        arrSize *= 2;
    }



    int getSize(void)
    {
        return top;
    }
    void push(T x)
    {
        if(top < arrSize-1)
        {
            top++;
            arr[top] = x;
        }
        else
        {
            //cout<<"full"<<endl;
            extend();
        }
    }
    T pop(void)
    {
        if(top > -1)
        {
            top--;
            cout<<arr[top+1]<<endl;
        }
        else
        {
            cout<<"empty"<<endl;
        }
    }
    void display(void)
    {
        for(int i=0; i<=top; i++)
        {
            cout<<"element "<<i<<" : "<<arr[i]<<endl;
        }
    }
    ~Stack()
    {
        cout<<"destructor"<<endl;
        delete[] arr;
    }
    friend void displayStack(Stack s);

};//Class End

void displayStack(Stack <int> s)
{
    for(int i=0; i<=s.top; i++)
    {
        cout<<"element "<<i<<" : "<<s.arr[i]<<endl;
    }
}
void displayStack(Stack <char> s)
{
    for(int i=0; i<=s.top; i++)
    {
        cout<<"element "<<i<<" : "<<s.arr[i]<<endl;
    }
}
void displayStack(Stack <double> s)
{
    for(int i=0; i<=s.top; i++)
    {
        cout<<"element "<<i<<" : "<<s.arr[i]<<endl;
    }
}

int main()
{
    Stack <double> stack1(5);
    stack1.pop();//empty
    stack1.push(1.1);
    stack1.push(5.3);
    stack1.push(6.4);
    stack1.pop();//6
    stack1.pop();//5
    stack1.push(7.7);
    stack1.pop();//7
    stack1.pop();//1
    stack1.pop();//Empty
    stack1.push(7.6);
    stack1.pop();//7
    //1567Empty7

    Stack <char> stack2(3);
    stack2.push('n');
    stack2.push('i');
    stack2.push('e');
    stack2.push('s');
    stack2.push('s');
    stack2.push('u');
    stack2.push('H');
    stack2.display();
    stack2.pop();
    stack2.pop();
    stack2.pop();
    stack2.pop();
    stack2.pop();
    stack2.pop();
    stack2.pop();
    stack2.pop();

    //stack1.display();
    displayStack(stack1);

    return 0;
}
