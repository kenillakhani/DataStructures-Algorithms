#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>

using namespace std;

void dfs(int node, unordered_map<int, list<int> > &adj, vector<int> &ap, int parent, vector<int> &low, vector<int> &disc, int &timer, unordered_map<int,bool> &vis)
{
    vis[node] = true;
    low[node] = disc[node] = timer++;

    int children = 0;

    for(auto neighbour: adj[node])
    {
        if(neighbour == parent)
        {
            continue;
        }

        if(!vis[neighbour])
        {
            children++;
            dfs(neighbour,adj,ap,node,low,disc,timer,vis);

            low[node] = min(low[node],low[neighbour]);

            if(low[neighbour] >= disc[node] && parent!=-1)
            {
                ap[node] = 1;
            }
        }
        else
        {
            low[node] = min(low[node],disc[neighbour]);
        }
    }

    if(parent == -1 && children > 1)
    {
        ap[node] = 1;
    }
}

int main()
{
    int v = 5;
    int e = 5;

    vector<pair<int,int> > edges;
    edges.push_back(make_pair(0,3));
    edges.push_back(make_pair(3,4));
    edges.push_back(make_pair(0,4));
    edges.push_back(make_pair(0,1));
    edges.push_back(make_pair(1,2));

    unordered_map<int, list<int> > adj;

    for(int i=0;i<edges.size();i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> disc(v,-1);
    vector<int> low(v,-1);
    unordered_map<int,bool> vis;
    vector<int> ap(v,0);

    int timer = 0;

    for(int i=0;i<v;i++)
    {
        if(!vis[i])
        {
            dfs(i,adj,ap,-1,low,disc,timer,vis);
        }
    }

    cout<<"Articulation Points: ";
    for(int i=0;i<ap.size();i++)
    {
        if(ap[i]!=0)
            cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}