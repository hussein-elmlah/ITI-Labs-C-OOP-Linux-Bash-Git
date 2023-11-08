#include <iostream>

using namespace std;

class Queue
{
private:
    int* arr;
    int arrSize;
    int top;
public:
    Queue(int arraySize)
    {
        cout<<"constructor"<<endl;
        arrSize = arraySize;
        arr = new int[arrSize] {0};
        top = -1;
    }
    int getSize(void)
    {
        return top;
    }
    void enque(int x)
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
    int denque(void)
    {
        if(top > -1)
        {
            cout<<arr[0]<<endl;
            for(int i=0; i<=top; i++)
            {
                arr[i]=arr[i+1];
            }
            top--;
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
    ~Queue()
    {
        cout<<"destructor"<<endl;
        delete[] arr;
    }
    friend void displayQueue(Queue s);

};//Class End

void displayQueue(Queue s)
{
    for(int i=0; i<=s.top; i++)
    {
        cout<<"element "<<i<<" : "<<s.arr[i]<<endl;
    }
}

int main()
{
    Queue queue1(5);
    queue1.denque();
    queue1.enque(5);
    queue1.enque(7);
    queue1.enque(10);
    queue1.denque();//5
    queue1.denque();//7
    queue1.enque(11);
    queue1.denque();
    queue1.denque();
    queue1.denque();

    //queue1.display();
    //displayQueue(queue1);

    return 0;
}
