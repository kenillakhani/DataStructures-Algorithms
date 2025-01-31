#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>

using namespace std;

void makeSet(vector<int> &parent, vector<int> &rank, int n)
{
    for(int i=0;i<=n;i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(vector<int> &parent, int u)
{
    if(parent[u]!=u)
    {
        parent[u] = findParent(parent,parent[u]);
    }
    return u;
}

void unionSet(int u,int v, vector<int> &parent, vector<int> &rank)
{
    u = findParent(parent,u);
    v = findParent(parent,v);

    if(rank[u] < rank[v])
    {
        parent[u] = v;
    }
    else if(rank[u] > rank[v])
    {
        parent[v] = u;
    }
    else
    {
        parent[v] = u;
        rank[u]++;
    }
}
bool cmp(vector<int> &a, vector<int> &b)
{
    return a[2] < b[2];
}

int minimumSanningTree(vector<vector<int> > &edges, int n)
{
    sort(edges.begin(),edges.end(),cmp);
    vector<int> parent(n);
    vector<int> rank(n);
    makeSet(parent,rank,n);
    
    int minWeight = 0;

    for(int i=0;i<edges.size();i++)
    {
        int u = findParent(parent,edges[i][0]);
        int v = findParent(parent,edges[i][1]);

        int w = edges[i][2];

        if(u!=v)
        {
            minWeight += w;
            unionSet(u,v,parent,rank);
        }
    }
    return minWeight;
}