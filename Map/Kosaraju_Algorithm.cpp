#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<stack>

using namespace std;

void dfs(int node, unordered_map<int, list<int> > &adj, vector<bool> &visited, stack<int> &st)
{
    visited[node] = true;

    for(auto neighbour: adj[node])
    {
        if(!visited[neighbour])
        {
            dfs(neighbour,adj,visited,st);
        }
    }

    st.push(node);
}

void revDfs(int node, unordered_map<int, list<int> > &adjT, vector<bool> &visited)
{
    visited[node] = true;

    for(auto neighbour: adjT[node])
    {
        if(!visited[neighbour])
        {
            revDfs(neighbour,adjT,visited);
        }
    }
}

int stronglyConnectedComponents(int v, vector<vector<int> > &edges)
{
    unordered_map<int, list<int> > adj;

    for(int i=0;i<edges.size();i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    stack<int> st;
    vector<bool> visited(v,false);
    for(int i=0;i<v;i++)
    {
        if(!visited[i])
        {
            dfs(i,adj,visited,st);
        }
    }

    unordered_map<int, list<int> > adjT;

    for(int i=0;i<v;i++)
    {
        visited[i] = false;
        for(auto neighbour: adj[i])
        {
            adjT[neighbour].push_back(i);
        }
    }
    
    // OR
    
    // for(int i=0;i<edges.size();i++)
    // {
    //     int u = edges[i][0];
    //     int v = edges[i][1];

    //     adjT[v].push_back(u);
    // }

    int cnt = 0;

    while(!st.empty())
    {
        int node = st.top();
        st.pop();

        if(!visited[node])
        {
            cnt++;

            revDfs(node,adjT,visited);
        }
    }
    return cnt;
}