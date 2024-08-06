#include <iostream>
using namespace std;
class Nstack
{

public:
    int *arr;
    int *top;
    int *next;
    int n, k;
    int free;

    Nstack(int k1, int n1)
    {
        k = k1;
        n = n1;
        arr = new int[n];
        top = new int[k];
        next = new int[n];
        for (int i = 0; i < k; i++)
        {
            top[i] = -1;
        }
        free = 0;
        for (int i = 0; i < n - 1; i++)
        {
            next[i] = i + 1;
        }
        next[n - 1] = -1;
    }

    void push(int x, int m)
    {
        if (free == -1)
        {
            cout << "Stack Overflow";
            return;
        }

        int index = free;

        free = next[index];

        arr[index] = x;

        next[index] = top[m - 1];

        top[m - 1] = index;
    }

    int pop(int m)
    {
        if (top[m - 1] == -1)
        {
            cout << "(Stack Underflow) ";
            return -1;
        }

        int index = top[m - 1];

        top[m - 1] = next[index];

        next[index] = free;

        free = index;

        return arr[index];
    }
};
int main()
{
    Nstack ns(3, 10);
    ns.push(15, 2);
    ns.push(45, 2);
    ns.push(17, 1);
    ns.push(49, 1);
    ns.push(39, 2);
    ns.push(11, 3);

    cout << "Popped element from stack 2 is " << ns.pop(2) << endl;
    cout << "Popped element from stack 1 is " << ns.pop(1) << endl;
    cout << "Popped element from stack 2 is " << ns.pop(2) << endl;
    cout << "Popped element from stack 3 is " << ns.pop(3) << endl;
    cout << "Popped element from stack 3 is " << ns.pop(3) << endl;
    return 0;
}