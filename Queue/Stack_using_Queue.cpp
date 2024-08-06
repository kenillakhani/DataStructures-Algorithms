#include <iostream>
#include <queue>
using namespace std;
class stack
{

public:
    int n;
    queue<int> q1;
    queue<int> q2;

    stack()
    {
        n = 0;
    }
    void push(int x)
    {
        q2.push(x);
        n++;
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        queue<int> q = q1;
        q1 = q2;
        q2 = q;
    }
    void pop()
    {
        if (q1.empty())
        {
            return;
        }
        q1.pop();
        n--;
    }
    int top()
    {
        if (q1.empty())
        {
            return -1;
        }
        return q1.front();
    }
    int size()
    {
        return n;
    }
};
class stack2
{
public:
    int n;
    queue<int> q1;
    queue<int> q2;

    stack2()
    {
        n = 0;
    }
    void pop()
    {
        if (q1.empty())
        {
            return;
        }
        while (q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        n--;
        queue<int> q = q1;
        q1 = q2;
        q2 = q;
        return;
    }
    void push(int x)
    {
        q1.push(x);
        n++;
    }
    int top()
    {
        if (q1.empty())
        {
            return -1;
        }
        while (q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        return q1.front();
        q2.push(q1.front());

        queue<int> q = q1;
        q1 = q2;
        q2 = q;
    }
    int size()
    {
        return n;
    }
};
int main()
{
    stack2 s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.pop();
    cout << s.top() << endl;
    return 0;
}