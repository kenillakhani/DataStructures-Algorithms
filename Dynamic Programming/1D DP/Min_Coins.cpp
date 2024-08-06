#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int solveMem(vector<int> &num, int x, vector<int> &dp)
{
    if(x==0)
    {
        return 0;       
    }
    if(x<0)
    {
        return INT_MAX;
    }
    if(dp[x]!=-1)
    {
        return dp[x];
    }
    int mini = INT_MAX;

    for(int i=0;i<num.size();i++)
    {
        mini = min(mini,1+solveMem(num,x-num[i],dp));
    }

    dp[x] = mini;
    return dp[x];
}

int solveTab(vector<int> &num, int x)
{
    vector<int> dp(x+1,INT_MAX);
    dp[0] = 0;
    for(int i=1;i<=x;i++)
    {
        for(int j=0;j<num.size();j++)
        {
            if(i-num[j]>=0 && dp[i-num[j]]!=INT_MAX)
            {
                dp[i] = min(dp[i],1+dp[i-num[j]]);
            }
        }
    }
    return dp[x];
}

int minimumElement(vector<int> &num, int x)
{
    vector<int> dp(x+1,-1);
    int ans = solveTab(num,x);
    if(ans==INT_MAX)
    {
        return -1;
    }
    return ans;
}

int main()
{
    int n,x;
    cin>>n>>x;
    vector<int> num(n);
    for(int i=0;i<n;i++)
    {
        cin>>num[i];
    }
    cout<<minimumElement(num,x)<<endl;
    return 0;
}