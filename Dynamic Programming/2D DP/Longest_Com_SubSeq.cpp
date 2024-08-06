#include<iostream>
#include<vector>

using namespace std;

int solve(string& text1, string& text2, int i, int j, vector<vector<int> > &dp)
    {
        if(i == text1.length())
            return 0;

        if(j == text2.length())
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];
        
        int ans = 0;
        if(text1[i] == text2[j])
            ans = 1 + solve(text1,text2,i+1,j+1,dp);
        
        else
        {
            ans = max(solve(text1,text2,i,j+1,dp), solve(text1,text2,i+1,j,dp));
        }
        return dp[i][j] = ans;
    }

    int solveTab(string a, string b)
    {   
        vector<vector<int> > dp(a.length()+1, vector<int>(b.length()+1,0));
        for(int i=a.length()-1;i>=0;i--)
        {
            for(int j=b.length()-1;j>=0;j--)
            {
                int ans = 0;
                if(a[i] == b[j])
                    ans = 1 + dp[i+1][j+1];
        
                else
                {
                    ans = max(dp[i][j+1], dp[i+1][j]);
                }
                dp[i][j] = ans;  
            }
        }
        return dp[0][0];
    }

    int solveTabOPT(string a, string b)
    {   
        vector<int> curr(b.length()+1,0);
        vector<int> next(b.length()+1,0);

        for(int i=a.length()-1;i>=0;i--)
        {
            for(int j=b.length()-1;j>=0;j--)
            {
                int ans = 0;
                if(a[i] == b[j])
                    ans = 1 + next[j+1];
        
                else
                {
                    ans = max(curr[j+1], next[j]);
                }
                curr[j] = ans;  
            }
            next = curr;
        }
        return next[0];
    }

    int longestCommonSubsequence(string text1, string text2) {

        // vector<vector<int> > dp(text1.length()+1, vector<int>(text2.length()+1,-1));
        // return solve(text1, text2, 0, 0, dp);

        return solveTabOPT(text1,text2);
    }