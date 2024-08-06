#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int maxEnvelopes(vector<vector<int> >& envelopes) {

        int n = envelopes.size();
        if(n == 0)
            return 0;
        
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });

        
        vector<int> ans;
        ans.push_back(envelopes[0][1]);

        for(int i=1;i<n;i++)
        {
            if(envelopes[i][1] > ans.back())
                ans.push_back(envelopes[i][1]);
            
            else
            {
                int index = lower_bound(ans.begin(),ans.end(),envelopes[i][1]) - ans.begin();
                ans[index] = envelopes[i][1];
            }
        }
        return ans.size();
    }

int main()
{
    vector<vector<int> > envelopes;
    vector<int> temp;
    temp.push_back(5);
    temp.push_back(4);
    envelopes.push_back(temp);
    temp.clear();
    temp.push_back(6);
    temp.push_back(4);
    envelopes.push_back(temp);
    temp.clear();
    temp.push_back(6);
    temp.push_back(7);
    envelopes.push_back(temp);
    temp.clear();
    temp.push_back(2);
    temp.push_back(3);
    envelopes.push_back(temp);
    cout<<maxEnvelopes(envelopes)<<endl;
    return 0;
}