#include<iostream>
#include<vector>

using namespace std;

void subseq(string s,string out,int index,vector<string> & ans)
{
    if(index >= s.length())
    {
        ans.push_back(out);
        return;
    }

    // exclude
    subseq(s,out,index+1,ans);

    // include
    out.push_back(s[index]);
    subseq(s,out,index+1,ans);
}

int main()
{
    string s = "abcd";   
    vector<string > ans;
    string out="";
    subseq(s,out,0,ans);

    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<endl;

    cout<<endl;
    return 0;
}