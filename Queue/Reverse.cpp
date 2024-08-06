#include <iostream>
#include <queue>
#include <stack>
using namespace std;
void reverseK(queue<int> &q, int k)
{
    stack<int> s;
    for (int i = 0; i < k; i++)
    {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }

    int t = q.size() - k;

    while (t--)
    {
        int val = q.front();
        q.pop();
        q.push(val);
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

    reverseK(q, 2);
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    return 0;
}