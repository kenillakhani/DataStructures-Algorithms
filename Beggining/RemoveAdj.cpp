#include<iostream>
using namespace std;
string s;

void RmAdj()
{
    int i=0;
    while(i<s.length())
    {
        if(s[i]==s[i+1])
        {
            s.erase(i,2);
            if(i==0)
                i=0;
            else
                i-=2;
        }
        i++;
    }
}

int main()
{
    cin>>s;
    RmAdj();   
    cout<<s<<endl;  
    return 0;
}