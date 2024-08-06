#include<iostream>
#include<list>
#include<vector>
#include<unordered_map>

using namespace std;

int bellmonFord(int n ,int m, int src, int dest, vector<vector<int> > &edges)
{
    vector<int> dist(n+1,INT_MAX);
    dist[src] = 0;

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];

            if(dist[u]!=INT_MAX && (dist[u] + w < dist[v]))
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Check for negative weight cycle

    bool flag = false;

    for(int j=0;j<m;j++)
    {
        int u = edges[j][0];
        int v = edges[j][1];
        int w = edges[j][2];

        if(dist[u]!=INT_MAX && (dist[u] + w < dist[v]))
        {
            flag = true;
        }
    }

    if(flag)
    {
        cout<<"Negative weight cycle found"<<endl;
    }
    else
    {
        cout<<"Shortest distance from "<<src<<" to "<<dest<<" is "<<dist[dest]<<endl;
    }
    return 0;
}