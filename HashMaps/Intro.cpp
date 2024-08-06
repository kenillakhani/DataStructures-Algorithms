#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;
int main()
{
    // creation
    unordered_map<string, int> m;

    // insertion
    pair <string, int> p = make_pair("abc", 1);
    m.insert(p);

    pair < string, int > p2("def", 2);
    m.insert(p2);

    m["ghi"] = 3;

    // search
    cout<<m["abc"]<<endl;
    cout<<m.at("def")<<endl;

    // cout<<m.at("xyz")<<endl;
    cout<<m["xyz"]<<endl;
    cout<<m.at("xyz")<<endl;

    cout<<m.size()<<endl;

    cout<<m.count("ghi")<<endl;
    cout<<m.count("pqr")<<endl;
    cout<<m.count("xyz")<<endl;

    // deletion
    m.erase("abc");
    cout<<m.count("abc")<<endl;

    // traversal
    for(auto it = m.begin(); it != m.end(); it++)
    {
        cout<<it->first<<" "<<it->second<<endl;
    }

    for(auto x: m)
    {
        cout<<x.first<<" "<<x.second<<endl;
    }

    unordered_map<string, int> :: iterator it = m.begin();
    while(it != m.end())
    {
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }

    
    return 0;
}