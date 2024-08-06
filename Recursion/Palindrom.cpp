#include<iostream>
using namespace std;

bool palindrom(string s,int n)
{
    if(n==0 || n==1)
        return true;
    
    if(s[0]==s[n-1])
        return palindrom(s.substr(1,n-2),n-2);
    else
        return false;
}

int main()
{
    string s;
    cin>>s;
    int n = s.length();

    if(palindrom(s,n))
        cout<<"Palindrome."<<endl;
    else
        cout<<"Not Palindrom."<<endl;

    return 0;
}