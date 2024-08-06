#include <iostream>
#include <queue>
#include <stack>
using namespace std;
void reverse(queue<int> &q)
{
    if (q.empty())
    {
        return;
    }
    int data = q.front();
    q.pop();
    reverse(q);
    q.push(data);
}
void reverse2(queue<int> &q)
{
    stack<int> s;
    while (!q.empty())
    {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
}
int main()
{
    queue<int> q;

    for (int i = 0; i < 5; i++)
    {
        q.push(i);
    }
    cout << "Queue after Reverse elements: ";

    reverse2(q);
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    return 0;
}