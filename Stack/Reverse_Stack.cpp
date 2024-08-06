#include <iostream>
#include <stack>
using namespace std;

void insertB(stack<int> &s, int k)
{
    if (s.empty())
    {
        s.push(k);
        return;
    }
    int x = s.top();
    s.pop();
    insertB(s, k);
    s.push(x);
}
void reverseS(stack<int> &s)
{
    if (s.empty())
        return;
    int x = s.top();
    s.pop();
    reverseS(s);
    insertB(s, x);
}
int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    reverseS(s);
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    return 0;
}