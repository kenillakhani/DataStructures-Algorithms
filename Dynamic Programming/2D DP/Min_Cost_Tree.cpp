#include<iostream>
#include<vector>
#include<climits>
#include<map>

using namespace std;

int solve(vector<int> &arr, map<pair<int, int>, int> &maxi, int left, int right, vector<vector<int> > &dp) {
    if (left == right) {
        return 0; // Single element subarray, no cost
    }

    if(dp[left][right] != -1)
        return dp[left][right];

    int ans = INT_MAX;
    for (int i = left; i < right; i++) {
        int leftMax = maxi[{left, i}];
        int rightMax = maxi[{i + 1, right}];
        int cost = leftMax * rightMax + solve(arr, maxi, left, i, dp) + solve(arr, maxi, i + 1, right, dp);
        ans = min(ans, cost);
    }
    return dp[left][right] = ans;
}

int mctFromLeafValues(vector<int>& arr) {
    int n = arr.size();
    map<pair<int, int>, int> maxi;
    vector<vector<int> > dp(n+1,vector<int> (n,-1));

    // Precompute maximum values for all subarrays
    for (int i = 0; i < n; i++) {
        int currentMax = arr[i];
        for (int j = i; j < n; j++) {
            currentMax = max(currentMax, arr[j]);
            maxi[{i, j}] = currentMax;
        }
    }

    return solve(arr, maxi, 0, n-1,dp);
}