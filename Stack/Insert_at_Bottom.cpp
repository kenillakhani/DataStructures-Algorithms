#include <iostream>
#include <stack>
using namespace std;
void solve(stack<int> &s, int k)
{
    if (s.empty())
    {
        s.push(k);
        return;
    }
    int x = s.top();
    s.pop();
    solve(s, k);
    s.push(x);
}
void insertB(stack<int> &s, int k)
{
    solve(s, k);
}
int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    insertB(s, 9);
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    return 0;
}