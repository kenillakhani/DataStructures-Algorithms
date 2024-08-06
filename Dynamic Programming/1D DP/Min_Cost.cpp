#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

int solve(vector<int> &days, vector<int> &costs, int n, int index, vector<int> &dp)
{
    if (index >= n)
        return 0;

    if (dp[index] != -1)
        return dp[index];

    int option1 = costs[0] + solve(days, costs, n, index + 1, dp);

    int i = 0;
    for (i = index; i < n && days[i] < days[index] + 7; i++)
        ;

    int option2 = costs[1] + solve(days, costs, n, i, dp);

    for (i = index; i < n && days[i] < days[index] + 30; i++)
        ;

    int option3 = costs[2] + solve(days, costs, n, i, dp);

    dp[index] = min(option1, min(option2, option3));
    return dp[index];
}

int solveTab(vector<int> &days, vector<int> &costs, int n)
{
    vector<int> dp(n + 1, INT_MAX);
    dp[n] = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        int option1 = costs[0] + dp[i + 1];

        int j = 0;
        for (j = i; j < n && days[j] < days[i] + 7; j++);

        int option2 = costs[1] + dp[j];

        for (j = i; j < n && days[j] < days[i] + 30; j++)
            ;

        int option3 = costs[2] + dp[j];

        dp[i] = min(option1, min(option2, option3));
    }

    return dp[0];
}

int spaceOPtimized(vector<int> &days, vector<int> &costs, int n)
{
    int ans = 0;

    queue<pair<int, int> > month;
    queue<pair<int, int> > week;

    for(int day : days)
    {
        while(!month.empty() && month.front().first + 30 <= day)
        {
            month.pop();
        }

        while(!week.empty() && week.front().first + 7 <= day)
        {
            week.pop();
        }

        month.push({day, ans + costs[2]});
        week.push({day, ans + costs[1]});
        ans = min(ans + costs[0], min(week.front().second, month.front().second));
    }
    return ans;
}

int mincostTickets(vector<int> &days, vector<int> &costs)
{

    int n = days.size();
    vector<int> dp(n + 1, -1);
    return solve(days, costs, n, 0, dp);
}

int main()
{
    int n;
    cin >> n;

    vector<int> days(n);
    vector<int> costs(3);

    for (int i = 0; i < n; i++)
    {
        cin >> days[i];
    }

    for (int i = 0; i < 3; i++)
    {
        cin >> costs[i];
    }

    cout << mincostTickets(days, costs) << endl;
    return 0;
}