// Input: 1 2 3 4
// Output: 1 3 2 4

// Input: 11 12 13 14 15 16 17 18
// Output: 11 15 12 16 13 17 14 18

#include <iostream>
#include <stack>
#include <queue>

using namespace std;
void interleave(queue<int> &q)
{
    int n = q.size() / 2;
    queue<int> temp;
    for (int i = 0; i < n; i++)
    {
        int val = q.front();
        q.pop();
        temp.push(val);
    }
    while (!temp.empty())
    {
        int val = temp.front();
        temp.pop();
        q.push(val);
        val = q.front();
        q.pop();
        q.push(val);
    }
}
// With use of Stack only.
void interleaveS(queue<int> &q) // Move the function declaration above the code block
{
    int n = q.size() / 2;
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        st.push(q.front());
        q.pop();
    }
    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }
    for (int i = 0; i < n; i++)
    {
        q.push(q.front());
        q.pop();
    }
    for(int i=0;i<n;i++)
    {
        st.push(q.front());
        q.pop();
    }
    for(int i=0;i<n;i++)
    {
        q.push(st.top());
        st.pop();
        q.push(q.front());
        q.pop();
    }
}
int main()
{
    queue<int> qu;
    qu.push(11);
    qu.push(12);
    qu.push(13);
    qu.push(14);
    qu.push(15);
    qu.push(16);
    qu.push(17);
    qu.push(18);

    interleaveS(qu);

    while (!qu.empty())
    {
        cout << qu.front() << " ";
        qu.pop();
    }
    cout << endl;
    return 0;
}