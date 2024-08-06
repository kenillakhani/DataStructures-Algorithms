#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;
 
struct Item
{
    int value, weight;
};

static bool cmp(pair<double,Item> a, pair<double,Item> b)
{
    return a.first > b.first;
}

double FractionalKnapsack(int W, Item arr[], int n)
 {
    vector<pair<double, Item> > v;
 
    for(int i=0;i<n;i++)
    {
        double perUnitValue = (1.0 * arr[i].value)/arr[i].weight;
        v.push_back(make_pair(perUnitValue, arr[i]));
    }

    sort(v.begin(), v.end(), cmp);

    double ans = 0;
    for(int i=0;i<n;i++)
    {
        if(v[i].second.weight <= W)
        {
            ans += v[i].second.value;
            W -= v[i].second.weight;
        }
        else
        {
            ans += v[i].first * W;
            break;
        }
    }
    return ans;
 }

int main()
{
    int W = 50;
    Item arr[] = {{60, 10}, {100, 20}, {120, 30}};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    cout << "Maximum value we can obtain = " << FractionalKnapsack(W, arr, n);
    return 0;
}