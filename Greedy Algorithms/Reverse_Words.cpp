#include<iostream>
#include<string>

using namespace std;

string reverseWords(string S)
{
    string ans = "";
    string temp = "";
     
    for(int i=S.length()-1; i>=0; i--)
    {
        if(S[i] == '.')
        {
            ans = ans + temp + ".";
            temp = "";
        }
        else
        {
            temp = S[i] + temp;
        }
    }
    ans = ans + temp;
    return ans;
}

int main()
{
    string S = "i.like.this.program.very.much";
    cout<<reverseWords(S)<<endl;
    return 0;
}