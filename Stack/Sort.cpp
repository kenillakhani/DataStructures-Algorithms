#include <iostream>
#include <stack>
using namespace std;
void sortedInsert(stack<int> &s, int x)
{
    if (s.empty() || s.top() < x)
    {
        s.push(x);
        return;
    }

    int n = s.top();
    s.pop();
    sortedInsert(s, x);
    s.push(n);
}
void sortS(stack<int> &s)
{
    if (s.empty())
        return;

    int x = s.top();
    s.pop();
    sortS(s);
    sortedInsert(s, x);
}
int main()
{
    stack<int> s;
    s.push(22);
    s.push(17);
    s.push(3);
    s.push(9);
    s.push(55);

    sortS(s);
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    return 0;
}