#include<iostream>
#include<unordered_map>
#include<list>

using namespace std;

class graph{

    public:
        unordered_map<int, list<int> > adj;

        void addEdge(int u, int v, bool direction)
        {
            // direction = 0 -> undirected
            // direction = 1 -> directed

            adj[u].push_back(v);

            if(direction == 1)
            {
                adj[v].push_back(u);
            }
        }

        void printAdjList()
        {
            for(auto i : adj)
            {
                cout<<i.first<<" -> ";
                for(auto j:i.second)
                {
                    cout<<j<<", ";
                }
                cout<<endl;
            }
        }

};

int main()
{
    int n;
    cout << "Enter the number of Nodes: ";
    cin >> n;

    int e;
    cout << "Enter the number of Edges: ";
    cin >> e;

    graph g;

    for (int i = 0; i < e; i++)
    {
        int u, v;
        cout << "Enter edge " << i + 1 << " (format: u v): ";
        cin >> u >> v;
        g.addEdge(u, v, 0);
    }

    g.printAdjList();

    return 0;
}
