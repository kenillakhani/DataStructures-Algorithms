#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Job
{
    int id, deadline, profit;
};

static bool cmp(Job a, Job b)
{
    return a.profit > b.profit;
}

vector<int> jobScheduling(Job arr[], int n)
{
    sort(arr, arr+n, cmp);

    int maxiDealine = 0;
    for(int i=0;i<n;i++)
    {
        maxiDealine = max(maxiDealine, arr[i].deadline);
    }

    vector<int> schedule(maxiDealine+1, -1);

    int jobCount = 0, profit = 0;

    for(int i=0;i<n;i++)
    {
        int currProfit = arr[i].profit;
        int currJob = arr[i].id;
        int currDeadline = arr[i].deadline;

        for(int k=currDeadline;k>0;k--)
        {
            if(schedule[k] == -1)
            {
                schedule[k] = currJob;
                jobCount++;
                profit += currProfit;
                break;
            }
        } 
    }
    vector<int> ans;
    ans.push_back(jobCount);
    ans.push_back(profit);
    return ans;
}

int main()
{
    Job arr[] = {{1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30}};
    int n = sizeof(arr)/sizeof(arr[0]);

    vector<int> ans = jobScheduling(arr, n);
    cout << "Number of jobs = " << ans[0] << endl;
    cout << "Total profit = " << ans[1] << endl;
    return 0;
}