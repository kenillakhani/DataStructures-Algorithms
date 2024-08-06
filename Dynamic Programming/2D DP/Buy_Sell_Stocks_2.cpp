#include<iostream>
#include<vector>

using namespace std;

int solve(int index, int buy, vector<int> &prices,int limit, vector<vector<vector<int> > > &dp)
    {
        if(index == prices.size())
            return 0;

        if(limit == 0)
            return 0;

        if(dp[index][buy][limit] != -1)
            return dp[index][buy][limit];

        int profit = 0;
        if(buy)
        {
            profit = max((-prices[index] + solve(index+1,0,prices,limit,dp)) , solve(index+1,1,prices,limit,dp));
        }
        else
        {
            profit = max( prices[index] + solve(index+1,1,prices,limit-1,dp) , solve(index+1,0,prices,limit,dp));
        }
        return dp[index][buy][limit] = profit;
    }

    int solveTab(vector<int>& prices)
    {
        int n  = prices.size();
        vector<vector<vector<int> > > dp(n+1,vector<vector<int> > (2, vector<int>(3 ,0)));

        for(int index = n-1;index>=0;index--)
        {
            for(int buy = 0;buy<=1;buy++)
            {
                for(int limit=1;limit<=2;limit++)
                {
                int profit = 0;
                if(buy)
                {
                    profit = max((-prices[index] + dp[index+1][0][limit]) , dp[index+1][1][limit]);
                }
                else
                {
                    profit = max( prices[index] + dp[index+1][1][limit-1] , dp[index+1][0][limit]);
                }
                dp[index][buy][limit] = profit;
                }
            }
        }
        return dp[0][1][2];
    }

    int solveTabOPT(vector<int>& prices)
    {
        int n  = prices.size();

        vector<vector<int> > curr(2,vector<int>(3,0));
        vector<vector<int> > next(2,vector<int>(3,0)); 

        for(int index = n-1;index>=0;index--)
        {
            for(int buy = 0;buy<=1;buy++)
            {
                for(int limit=1;limit<=2;limit++)
                {
                int profit = 0;
                if(buy)
                {
                    profit = max((-prices[index] + next[0][limit]) , next[1][limit]);
                }   
                else
                {
                    profit = max( prices[index] + next[1][limit-1] , next[0][limit]);
                }
                curr[buy][limit] = profit;
                }
            }
            next = curr;
        }
        return next[1][2];
    }

    int maxProfit(vector<int>& prices) {
        
        // int n = prices.size();
        // vector<vector<vector<int> > > dp(n+1,vector<vector<int> > (2, vector<int>(3 ,-1)));
        // return solve(0,1,prices,2,dp);

        return solveTabOPT(prices);
    }