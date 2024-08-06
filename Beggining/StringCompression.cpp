#include<iostream>
using namespace std;
string s;

void stringComp()
{
    int i=0;
    int l=0;
    int k=-1;
    while(i<s.length())
    {

        while(i<s.length() && s[i]==s[i+1])
        {
            i++;
        }
        s[l]=s[i];
        l++;
        int x = i-k;
        if(x>1)
        {
        string cnt = to_string(x);
        int j=0;
        while(cnt[j]!='\0')
        {
            s[l]=cnt[j];
            l++;
            j++;
        }
        }
        k=i;
        i++;
    }
    int x=0;
    while(x<l)
    {
        cout<<s[x];
        x++;
    }
    cout<<endl;
}

int main()
{
    getline(cin,s);
    stringComp();
    
    return 0;
}