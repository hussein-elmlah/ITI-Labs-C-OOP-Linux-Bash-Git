#include <iostream>

using namespace std;

class Stack
{
private:
    int* arr;
    int arrSize;
    int top;
public:
    /*
    Stack(Stack &s)
    {
        arrSize = s.arrSize;
        top = s.top;
        arr = new int[arrSize]{0};
        for(int i=0; i<=top; i++)
        {
            arr[i] = s.arr[i];
        }
    }
    */
    Stack(int arraySize)
    {
        cout<<"constructor"<<endl;
        arrSize = arraySize;
        arr = new int[arrSize] {0};
        top = -1;
    }

    Stack operator = (Stack s)
    {
        arrSize = s.arrSize;
        top = s.top;
        delete []arr;
        arr = new int[arrSize] {0};
        for(int i=0; i<=top; i++)
        {
            arr[i]=s.arr[i];
        }
        return *this;
    }

    int getSize(void)
    {
        return top;
    }
    void push(int x)
    {
        if(top < arrSize-1)
        {
            top++;
            arr[top] = x;
        }
        else
        {
            cout<<"full"<<endl;
        }
    }
    int pop(void)
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

void displayStack(Stack s)
{
    for(int i=0; i<=s.top; i++)
    {
        cout<<"element "<<i<<" : "<<s.arr[i]<<endl;
    }
}

void fun(Stack s)
{
    s.pop();
    s.pop();
}

int main()
{

    Stack stack1(5);
    stack1.push(2);
    stack1.push(3);
    stack1.push(5);
    stack1.push(6);
    stack1.push(7);
    Stack stack2(5);
    stack2=stack1;
    stack1.pop();
    stack1.push(9);
    cout<<"========================="<<endl;
    stack1.display();
    cout<<"========================="<<endl;
    stack2.display();
  //  stack1.pop();
   // stack2.pop();
    //stack2.pop();
    //stack2.pop();

    /*
    fun(stack1);
    stack1.pop();//empty
    stack1.push(1);
    stack1.push(5);
    stack1.push(6);
    stack1.pop();//6
    stack1.pop();//5
    fun(stack1);
    fun(stack1);
    stack1.push(7);
    stack1.pop();//7
    stack1.pop();//1
    stack1.pop();//Empty
    stack1.push(7);
    stack1.pop();//7
    //1567Empty7
    */



    //stack1.display();
    //displayStack(stack1);

    return 0;
}
