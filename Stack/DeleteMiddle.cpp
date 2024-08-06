#include<iostream>
#include<stack>
using namespace std;
void solve(stack<int> &s,int cnt,int size)
{
    if(s.empty() || cnt == size/2)
    {
        s.pop();
        return;
    }
    int x = s.top();
    s.pop();
    solve(s,cnt+1,size);
    s.push(x);
}
void deleteMiddle(stack<int> &s, int size)
{
   int cnt = 0;
   solve(s,cnt,size);
}
int main()
{
    stack<int> s;   
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    deleteMiddle(s, s.size());
    
    while(!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}