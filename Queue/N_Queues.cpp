#include <iostream>
using namespace std;
class kQueue
{
public:
    int n;
    int k;
    int *arr;
    int *front;
    int *rear;
    int free;
    int *next;

public:
    kQueue(int n, int k)
    {

        this->n = n;
        this->k = k;

        free = 0;
        arr = new int[n];
        front = new int[k];
        rear = new int[k];
        next = new int[n];

        for (int i = 0; i < n; i++)
        {
            next[i] = i + 1;
        }
        next[n - 1] = -1;

        for (int i = 0; i < k; i++)
        {
            front[i] = rear[i] = -1;
        }
    }

    void enqueue(int ele, int qn)
    {
        if (free == -1)
        {
            cout << "Queue is full." << endl;
            return;
        }

        int index = free;
        free = next[index];

        if (front[qn - 1] == -1)
        {
            front[qn - 1] = index;
        }
        else
        {
            next[rear[qn - 1]] = index;
        }

        next[index] = -1;
        rear[qn - 1] = index;
        arr[index] = ele;
    }

    int dEqueue(int qn)
    {
        if (front[qn - 1] == -1)
        {
            cout << "Queue is empty." << endl;
            return -1;
        }

        int index = front[qn - 1];

        front[qn - 1] = next[index];
        if (next[index] == -1)
        {
            rear[qn - 1] = -1;
        }
        next[index] = free;
        free = index;

        return arr[index];
    }
};
int main()
{
    kQueue kq(10, 3);
    kq.enqueue(10, 1);
    kq.enqueue(15, 1);
    kq.enqueue(20, 2);
    kq.enqueue(25, 1);

    cout << kq.dEqueue(1) << endl;
    cout << kq.dEqueue(2) << endl;
    cout << kq.dEqueue(1) << endl;
    cout << kq.dEqueue(1) << endl;

    kq.enqueue(30, 2);
    kq.enqueue(35, 1);

    cout << kq.dEqueue(1) << endl;
    cout << kq.dEqueue(2) << endl;

    return 0;
}