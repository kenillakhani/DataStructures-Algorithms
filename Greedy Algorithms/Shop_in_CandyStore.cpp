#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> candyStore(int candies[], int N, int K)
{
    sort(candies, candies + N);
    int minCost = 0; 
    int n = N;
    for (int i = 0; i < n; i++)
    {
        minCost += candies[i];
        n -= K;
    }

    int maxi = 0;
    int buy = N-1;
    int free = 0;

    while(free<=buy)
    {
        maxi += candies[buy];
        buy--;
        free+=K;
    }

    vector<int> ans;
    ans.push_back(minCost);
    ans.push_back(maxi);
    return ans;
}

int main()
{
    int N = 4;
    int K = 2;
    int candies[] = {3, 2, 1, 4};
    vector<int> ans = candyStore(candies, N, K);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}