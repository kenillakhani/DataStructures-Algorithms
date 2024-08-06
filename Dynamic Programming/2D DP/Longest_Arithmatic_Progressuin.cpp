#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

int solve(int a[],int index,int diff)
{
    if(index < 0)
    {
        return 0;
    }

    int ans = 0;
    for(int j = index-1;j>=0;j--)
    {
        if(a[index] - a[j] == diff)
        {
            ans = max(ans, 1+solve(a,j,diff));
        }
    }
    return ans;
}

int lengthOfLongestAP(int a[],int n)
{
    // if(n <= 2)
    // {
    //     return n;
    // }

    // int ans = 0;

    // for(int i = 0;i<n;i++)
    // {
    //     for(int j = i+1;j<n;j++)
    //     {
    //         ans = max(ans, 2+solve(a,i,a[j]-a[i]));
    //     }
    // }
    // return ans;

    if(n <= 2)
    {
        return n;
    }

    int ans = 0;
    unordered_map<int,int> dp[n+1];

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            int diff = a[i] - a[j];
            int cnt = 1;

            if(dp[j].count(diff))
            {
                cnt = dp[j][diff];
            }
            dp[i][diff] = cnt+1;
            ans = max(ans, dp[i][diff]);
        }
    }
    return ans;
}