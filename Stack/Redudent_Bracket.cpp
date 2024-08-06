#include <iostream>
#include <stack>
using namespace std;
bool redudentBr(string str)
{
    stack<char> s;
    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            s.push(ch);
        }
        else
        {
            if (ch == ')')
            {
                bool isRedudent = true;

                while (s.top() != '(')
                {
                    char top = s.top();
                    if (top == '+' || top == '-' || top == '*' || top == '/')
                    {
                        isRedudent = false;
                    }
                    s.pop();
                }

                if (isRedudent)
                    return true;

                s.pop();
            }
        }
    }
    return false;
}
int main()
{
    string str = "((a+b)*c)";
    if (redudentBr(str))
        cout << "Redudent." << endl;
    else
        cout << "Not Redudent." << endl;

    return 0;
}