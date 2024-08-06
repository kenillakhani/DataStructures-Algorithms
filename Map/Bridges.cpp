#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>

using namespace std;

void dfs(int node, unordered_map<int, list<int> > &adj, vector<bool> &visited, int &parent, vector<int> &low, vector<int> &disc, int &timer, vector<vector<int> > &result)
{
    visited[node] = true;
    low[node] = disc[node] = timer++;

    for(auto neighbour: adj[node])
    {
        if(neighbour == parent)
        {
            continue;
        }

        if(!visited[neighbour])
        {
            dfs(neighbour,adj,visited,node,low,disc,timer,result);

            low[node] = min(low[node],low[neighbour]);

            // check if bridge
            if(low[neighbour] > disc[node])
            {
                result.push_back({node,neighbour});
            }
        }
        else
        {
            // back edge
            low[node] = min(low[node],disc[neighbour]);
        }
    }
} 

vector<vector<int> > findBridges(vector<vector<int> > &edges, int v,int e)
{
    unordered_map<int, list<int> > adj;

    for(int i=0;i<e;i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> disc(v,-1);
    vector<int> low(v,-1);
    int parent = -1;
    vector<bool> visited(v,false);
    int timer = 0;

    vector<vector<int> > result;

    for(int i=0;i<v;i++)
    {
        if(!visited[i])
        {
            dfs(i,adj,visited,parent,low,disc,timer,result);
        }
    }

    return result;
}