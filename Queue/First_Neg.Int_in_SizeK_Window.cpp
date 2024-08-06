#include <iostream>
#include <vector>
#include <deque>
using namespace std;

#include <deque> // Include the necessary header file

vector<int> functionn(int arr[], int n, int k)
{
    deque<int> dq;
    vector<int> ans;

    for (int i = 0; i < k; i++)
    {
        if (arr[i] < 0)
        {
            dq.push_back(i);
        }
    }
    if (dq.empty())
    {
        ans.push_back(0);
    }
    else
    {
        ans.push_back(arr[dq.front()]);
    }
    for (int i = k; i < n; i++)
    {
        if (!dq.empty() && dq.front() == i - k)
        {
            dq.pop_front();
        }
        if (arr[i] < 0)
        {
            dq.push_back(i);
        }
        if (dq.empty())
        {
            ans.push_back(0);
        }
        else
        {
            ans.push_back(arr[dq.front()]);
        }
    }
    return ans;
}
int main()
{
    int arr[] = {-8, 2, 3, -6, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    int k = 2;

    vector<int> ans = functionn(arr, n, k);

    for (int x : ans)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}