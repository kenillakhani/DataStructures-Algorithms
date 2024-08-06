#include<iostream>
#include<vector>

using namespace std;

int solve(int dice, int faces, int target, vector<vector<int> > &dp)
{
    if(target<0)
        return 0;   
    
    if(dice==0 && target!=0)
        return 0;
    
    if(dice==0 && target==0)
        return 1;
    
    if(target == 0 && dice!=0)
        return 0;

    if(dp[dice][target]!=-1)
        return dp[dice][target];
    
    int ans=0;

    for(int i=1;i<=faces;i++)
    {
        ans = ans + solve(dice-1,faces,target-i,dp);
    }
    return dp[dice][target] = ans;
}

int solveTab(int m, int n, int x)
{
    // Space Opimization Possible
    // Do it at your hand.
    
    vector<vector<int> > dp(m+1,vector<int>(x+1,0));
    dp[0][0] = 1;

    for(int dice=1;dice<=m;dice++)
    {
        for(int target=1;target<=x;target++)
        {
            int ans = 0;

            for(int k=1;k<=n;k++)
            {
                if(target-k>=0)
                    ans += dp[dice-1][target-k];
            }
            dp[dice][target] = ans; 
        } 
    }
    return dp[m][x];
}

int noOfWays(int m, int n, int x)
{
    // vector<vector<int> > dp(m+1,vector<int>(x+1,-1));
    // return solve(m,n,x,dp);

    return solveTab(m,n,x);
}

int main()
{
    int m=4,n=2,x=1;
    cout<<noOfWays(m,n,x)<<endl;
    return 0;
}