#include <iostream>
#include <queue>
using namespace std;
class Deuqeue
{
public:
    int front, rear, size;
    int *array;

    Deuqeue()
    {
        size = 10000;
        array = new int[size];
        front = rear = -1;
    }

    bool push_front(int data)
    {
        if (front == (rear + 1) % size)
        {
            cout << "Queue is full." << endl;
            return false;
        }
        else if (front == -1)
        {
            front = rear = 0;
            array[front] = data;
        }
        else if (front == 0)
        {
            front = size - 1;
            array[front] = data;
        }
        else
        {
            front = front - 1;
            array[front] = data;
        }
        return true;
    }
    bool push_back(int data)
    {
        if (front == (rear + 1) % size)
        {
            cout << "Queue is full." << endl;
            return false;
        }
        else if (front == -1)
        {
            front = rear = 0;
            array[rear] = data;
        }
        else if (rear == size - 1)
        {
            rear = 0;
            array[rear] = data;
        }
        else
        {
            rear = rear + 1;
            array[rear] = data;
        }
        return true;
    }
    int pop_front()
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
            else if (front == size - 1)
                front = 0;
            else
                front = front + 1;
            return x;
        }
    }
    int pop_back()
    {
        if (front == -1)
        {
            cout << "Queue is empty." << endl;
            return -1;
        }
        else
        {
            int x = array[rear];
            if (front == rear)
                front = rear = -1;
            else if (rear == 0)
                rear = size - 1;
            else
                rear = rear - 1;
            return x;
        }
    }
};
int main()
{
    Deuqeue q;
    q.push_front(10);
    q.push_front(20);

    cout << q.pop_front() << endl;
    cout << q.pop_back() << endl;

    return 0;
}