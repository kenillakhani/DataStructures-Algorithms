#include<iostream>
#include<stack>
using namespace std;
int main()
{
    string str = "Hello";

    stack<char> s;

    for(int i = 0; i < str.length(); i++)
    {
        s.push(str[i]);
    } 
    string ans = "";
    cout << "The reversed string is: ";
    while(!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    cout << ans << endl;
    return 0;
}