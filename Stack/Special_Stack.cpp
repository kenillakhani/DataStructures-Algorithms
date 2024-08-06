#include <iostream>
#include <stack>
using namespace std;
class specialStack
{

public:
    stack<int> s;
    int mini;

    void push(int data)
    {
        if (s.empty())
        {
            s.push(data);
            mini = data;
        }
        else
        {
            if (data > mini)
                s.push(data);

            else
            {
                s.push(2 * data - mini);
                mini = data;
            }
        }
    }
    int pop()
    {
        if (s.empty())
            return -1;
        else
        {
            int curr = s.top();
            s.pop();
            if (curr < mini)
            {
                int x = mini;
                mini = 2 * mini - curr;
                return x;
            }
            else
                return curr;
        }
    }
    int top()
    {
        if (s.empty())
            return -1;
        else
        {
            int curr = s.top();
            if (curr < mini)
                return mini;
            else
                return curr;
        }
    
    }
    bool isEmpty()
    {
        return s.empty();
    }
    int getMin()
    {
        if (s.empty())
            return -1;
        else
            return mini;
    }
};
int main()
{
    specialStack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.getMin() << endl;
    s.push(5);
    cout << s.getMin() << endl;
    s.pop();
    cout << s.getMin() << endl;

    return 0;
}