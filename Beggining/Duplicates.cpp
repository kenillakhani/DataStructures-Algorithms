#include <iostream>
#include <vector>
using namespace std;

vector<int> findDuplicates(vector<int> &nums)
{

    vector<int> ans;
    sort(nums.begin(), nums.end());
    int s = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        if (!(s ^ nums[i]))
        {
            ans.push_back(nums[i]);
            i++;
        }
        s = nums[i];
    }

    return ans;
}
int main()
{
    int ar[] = {1, 5, 4, 3, 3, 7, 4, 9, 6};

    int n = sizeof(ar)/sizeof(int);
    vector<int> arr(ar,ar+n);  // if size = n then form 1 to n occurence none , once or twice
    vector<int> ans = findDuplicates(arr);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}