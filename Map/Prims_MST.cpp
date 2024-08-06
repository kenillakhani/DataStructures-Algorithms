#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>

using namespace std;

vector<pair<pair<int,int>, int> > calculateMST(int n,int m,vector<pair<pair<int,int>, int> > &g)
{
    unordered_map<int, list<pair<int,int> > > adj;
    for(int i=0;i<m;i++)
    {
        int u = g[i].first.first; 
        int v = g[i].first.second;
        int w = g[i].second;

        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    vector<int> parent(n+1,-1);
    vector<int> key(n+1,INT_MAX);
    vector<bool> mstSet(n+1,false);

    key[0] = 0;
    parent[0] = -1;

    for(int i=1;i<=n;i++)
    {
        int minKey = INT_MAX;
        int u = -1;

        for(int j=1;j<=n;j++)
        {
            if(!mstSet[j] && key[j]<u)
            {
                minKey = key[j];
                u = j;
            }
        }

        mstSet[u] = true;

        for(auto neighbour: adj[u])
        {
            int v = neighbour.first;
            int w = neighbour.second;

            if(!mstSet[v] && w<key[v])
            {
                parent[v] = u;
                key[v] = w;
            }
        }
    }

    vector<pair<pair<int,int>, int> > result;

    for(int i=1;i<n;i++)
    {
        result.push_back(make_pair(make_pair(parent[i],i),key[i]));
    } 
    return result; 
}