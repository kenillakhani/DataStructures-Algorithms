#include<iostream>
#include<vector>

using namespace std;

int solve(vector<int>& nums1, vector<int>& nums2, int index, bool swapped, vector<vector<int> > &dp)
{
    if(index == nums1.size())
    {
        return 0;
    }

    if(dp[index][swapped] != -1)
    {
        return dp[index][swapped];
    }

    int ans = INT_MAX;
    int prev1 = nums1[index - 1];
    int prev2 = nums2[index - 1];

    if(swapped)
        swap(prev1, prev2);
    
    if(nums1[index] > prev1 && nums2[index] > prev2)
    {
        ans = solve(nums1, nums2, index + 1, false, dp);
    }
    if(nums1[index] > prev2 && nums2[index] > prev1)
    {
        ans = min(ans, 1 + solve(nums1, nums2, index + 1, true, dp));
    }
    dp[index][swapped] = ans;
    return ans; 
}

int solveTab(vector<int>& nums1, vector<int>& nums2)
{   
    int n = nums1.size();
    vector<vector<int> > dp(n+1, vector<int>(2,0));

    for(int index = n-1;index >= 1;index--)
    {
        for(int swapped = 1;swapped>=0;swapped--)
        {
        int ans = INT_MAX;
        int prev1 = nums1[index - 1];
        int prev2 = nums2[index - 1];

        if(swapped)
            swap(prev1, prev2);
    
        if(nums1[index] > prev1 && nums2[index] > prev2)
        {
            ans = dp[index + 1][0];
        }
        if(nums1[index] > prev2 && nums2[index] > prev1)
        {
            ans = min(ans, 1 + dp[index + 1][1]);
        }
        dp[index][swapped] = ans;
        }
    }
    return dp[1][0];
}

int solveTabOpt(vector<int>& nums1, vector<int>& nums2)
{   
    int n = nums1.size();
    int swapp = 0;
    int noSwapp = 0;
    int currswapp = 0;
    int currnoSwapp = 0;

    for(int index = n-1;index >= 1;index--)
    {
        for(int swapped = 1;swapped>=0;swapped--)
        {
        int ans = INT_MAX;
        int prev1 = nums1[index - 1];
        int prev2 = nums2[index - 1];

        if(swapped)
            swap(prev1, prev2);
    
        if(nums1[index] > prev1 && nums2[index] > prev2)
        {
            ans = noSwapp;
        }
        if(nums1[index] > prev2 && nums2[index] > prev1)
        {
            ans = min(ans, 1 + swapp); 
        }
        if(swapped)
            currswapp = ans;
        else
            currnoSwapp = ans;
        }
        swapp = currswapp;
        noSwapp = currnoSwapp;
    }
    return min(swapp, noSwapp);
}

int minSwap(vector<int>& nums1, vector<int>& nums2) 
{
    nums1.insert(nums1.begin(), -1);
    nums2.insert(nums2.begin(), -1);
     
    bool swapped = false;

    int n = nums1.size();
    vector<vector<int> > dp(n, vector<int>(2, -1));
    return solve(nums1, nums2, 1, swapped,dp);        
}