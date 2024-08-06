#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int findMinDiff(vector<int> A, int N, int M)
{
    sort(A.begin(), A.end());
    int ans = INT_MAX;

    int i = 0;
    int j = M-1;

    while(j < N)
    {
        ans = min(ans, A[j] - A[i]);
        i++;
        j++;
    }
    return ans;
}

int main()
{
    vector<int> A = {3, 4, 1, 9, 56, 7, 9, 12};
    int N = A.size();
    int M = 5;
    cout<<findMinDiff(A, N, M)<<endl;
    return 0;
}