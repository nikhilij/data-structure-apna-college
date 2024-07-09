// wap to learn Queue in cpp
// here we will use array implementation of Queue

#include <iostream>
using namespace std;

#define MAX 20

class Queue
{
    int *arr;
    int front;
    int back;

public:
    Queue()
    {
        arr = new int[MAX];
        front = -1;
        back = -1;
    }

    bool isFull()
    {
        if (back == MAX - 1)
        {
            return true;
        }
        return false;
    }

    bool isEmpty()
    {
        if (front == -1 || front > back)
        {
            return true;
        }
        return false;
    }

    void enqueue(int x)
    {
        if (isFull())
        {
            cout << "Queue is Full";
            return;
        }
        
        if (front == -1)
        {
            front=0;
        }
        arr[++back]=x;
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty";
            return -1;
        }
        int result = arr[front];
        if(front==back){
            front=back=-1;
        }else{
            front++;
        }
        return result;
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty";
            return -1;
        }
        return arr[front];
    }

    void display()
    {
        for (int i = front; i <= back; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.display();  
    cout<<q.dequeue()<<endl; 
    cout<<q.peek();

}
