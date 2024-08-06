#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool cmp(pair<int,int> a,pair<int,int> b)
{
    return a.second > b.second;
}

int maxMeetings(int start[], int end[], int n)
{
    vector<pair<int,int> > v;
    for(int i=0;i<n;i++)
    {
        v.push_back({start[i],end[i]});
    }
    sort(v.begin(),v.end(),cmp);

    int count = 1;
    int endtime = v[0].second;

    for(int i=1;i<n;i++)
    {
        if(v[i].first > endtime)
        {
            count++;
            endtime = v[i].second;
        }
    }
    return count;
}

int main()
{
    int n;
    cin>>n;
    int start[n],end[n];
    for(int i=0;i<n;i++)
    {
        cin>>start[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>end[i];
    }
    cout<<maxMeetings(start,end,n);
    return 0;
}