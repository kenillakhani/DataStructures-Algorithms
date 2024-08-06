#include<iostream>
#include<queue>
using namespace std;
string functionn(string & str)
{
    unordered_map<char, int> mp;
    queue<char> q;
    string ans = "";

    for(int i=0;i<str.length();i++)
    {
        char ch = str[i];

        mp[ch]++;

        q.push(ch);
        while(!q.empty())
        {
            if(mp[q.front()] > 1)
            {
                q.pop();
            }
            else
            {
                ans += q.front();
                break;
            }
        }
        if(q.empty())
        {
            ans += '#';
        }
    }
    return ans;
}
int main()
{
    string str = "aabc";

    string ans = functionn(str);   
    int n = ans.length();
    for(int i=0;i<n;i++)
    {
        cout<<ans[i];
    }
    cout<<endl;
    return 0;
}