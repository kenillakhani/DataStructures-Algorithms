#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<set>

using namespace std;

vector<int> dijkstra(vector<vector<int> > &vec, int vertices, int edges, int source)
{
    unordered_map<int, list<pair<int,int> > > adj;
    for(int i=0;i<edges;i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    vector<int> distance(vertices,INT_MAX); 

    set<pair<int,int> > st; 

    distance[source] = 0;
    st.insert(make_pair(0,source));

    while(!st.empty())
    {
        auto top = *(st.begin());

        int nodeDistance = top.first;
        int topNode = top.second;

        st.erase(st.begin());

        for(auto neighbour: adj[topNode])
        {
            int v = neighbour.first;
            int w = neighbour.second;

            if(distance[v] > nodeDistance + w)
            {
                auto record = st.find(make_pair(distance[v],v));

                if(record!=st.end())
                {
                    st.erase(record);
                }

                distance[v] = distance[topNode] + w;
                st.insert(make_pair(distance[v],v));
            }
        }
    } 
    return distance;
}