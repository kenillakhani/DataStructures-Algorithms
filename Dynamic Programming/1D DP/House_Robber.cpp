#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int solveSpaceOptimized(vector<int> &nums, int n)
{
    int a = nums[0];
    int b = 0;

    for(int i=1;i<n;i++)
    {
        int c = max(b+nums[i],a);
        b = a;
        a = c;
    }

    return a;
}

int houseRobber(vector<int> &valueInHouse)
{
    int n = valueInHouse.size();

    vector<int> first, second;

    if(n==1)
    {
        return valueInHouse[0];
    }

    for(int i=0;i<n-1;i++)
    {
        first.push_back(valueInHouse[i]);
    }

    for(int i=1;i<n;i++)
    {
        second.push_back(valueInHouse[i]);
    }

    int ans = max(solveSpaceOptimized(first,n-1),solveSpaceOptimized(second,n-1));
    return ans;
}