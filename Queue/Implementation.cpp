#include <iostream>
using namespace std;
class Queue
{
public:
    int front, rear, size;
    int *array;

    Queue()
    {
        size = 10000;
        array = new int[size];
        front = rear = 0;
    }
public:
    void enqueue(int data)
    {
        if (rear == size)
        {
            cout << "Queue is full." << endl;
            return;
        }
        else
        {
            array[rear] = data;
            rear++;
        }
    }
    int dequeue()
    {
        if (front == rear)
        {
            cout << "Queue is empty." << endl;
            return -1;
        }
        else
        {
            int x = array[front];
            array[front] = -1;
            front++;
            if (front == rear)
                front = rear = 0;

            return x;
        }
    }
    int frunt()
    {
        if (front == rear)
        {
            cout << "Queue is empty." << endl;
            return -1;
        }
        else
            return array[front];
    }
    bool empty()
    {
        if (front == rear)
            return true;
        else
            return false;
    }
};
int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(20);

    cout << q.frunt() << endl;
    cout<< q.dequeue() << endl;
    cout << q.frunt() << endl;
    cout << q.empty() << endl;

    return 0;
}