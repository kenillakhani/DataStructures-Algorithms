#include<iostream>
using namespace std;

char MaxOccure(string s)
{
    int count[26]={0};
    for(int i=0;i<s.length();i++)
    {
        count[s[i]-'a']++;
    }
    int max=0;
    char result;
    for(int i=0;i<26;i++)
    {
        if(count[i]>max)
        {
            max=count[i];
            result=i+'a';
        }
    }
    return result;
}
int main()
{
    string s;
    cin>>s;

    cout<<MaxOccure(s);
    
    return 0;
}