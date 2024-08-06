#include<iostream>
using namespace std;
class CircularQueue
{
public:
    int front, rear, size;
    int *array;

    CircularQueue()
    {
        size = 10000;
        array = new int[size];
        front = rear = -1;
    }

public:
    void enqueue(int data)
    {
        if ((rear + 1) % size == front)
        {
            cout << "Queue is full." << endl;
            return;
        }
        else
        {
            if (front == -1)
                front = 0;
            rear = (rear + 1) % size;
            array[rear] = data;
        }
    }
    int dequeue()
    {
        if (front == -1)
        {
            cout << "Queue is empty." << endl;
            return -1;
        }
        else
        {
            int x = array[front];
            if (front == rear)
                front = rear = -1;
            else
                front = (front + 1) % size;
            return x;
        }
    }
    int frunt()
    {
        if (front == -1)
        {
            cout << "Queue is empty." << endl;
            return -1;
        }
        else
            return array[front];
    }
    bool empty()
    {
        if (front == -1)
            return true;
        else
            return false;
    }
      
};
int main()
{
    
    return 0;
}