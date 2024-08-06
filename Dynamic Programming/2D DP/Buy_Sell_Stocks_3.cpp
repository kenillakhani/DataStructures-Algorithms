#include<iostream>
#include<vector>

using namespace std;

int solveTabOPT(vector<int>& prices, int k)
    {
        int n  = prices.size();

        vector<vector<int> > curr(2,vector<int>(k+1,0));
        vector<vector<int> > next(2,vector<int>(k+1,0)); 

        for(int index = n-1;index>=0;index--)
        {
            for(int buy = 0;buy<=1;buy++)
            {
                for(int limit=1;limit<=k;limit++)
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
        return next[1][k];
    }

    int maxProfit(int k, vector<int>& prices) {
        
        return solveTabOPT(prices,k);
    }