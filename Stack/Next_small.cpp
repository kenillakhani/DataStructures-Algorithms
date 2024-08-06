#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int> nextSmallerElement(vector<int> arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans;

    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];
        while (s.top() != -1 && s.top() >= curr)
        {
            s.pop();
        }
        ans.push_back(s.top());
        s.push(curr);
    }
    return ans;
}
int main()
{
    vector<int> arr;
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(4);
    arr.push_back(3);

    vector<int> ans = nextSmallerElement(arr, arr.size());
    cout << "Next smaller element of each number in the array is : ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}