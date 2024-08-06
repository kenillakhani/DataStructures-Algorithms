#include<iostream>
#include<vector>
using namespace std;

void subsets(vector<int> nums, vector<vector<int> > &ans, vector<int> sub, int index)
{
    if(index >= nums.size())
    {
        ans.push_back(sub);
        return;
    }

    // exclude
    subsets(nums,ans,sub,index+1);

    // include
    sub.push_back(nums[index]);
    subsets(nums,ans,sub,index+1);
}

int main()
{
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(5);
    nums.push_back(6);
    nums.push_back(1);
    vector<vector<int> > ans;
    vector<int> x;
    subsets(nums,ans,x,0);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
            cout<<ans[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
    return 0;
}
