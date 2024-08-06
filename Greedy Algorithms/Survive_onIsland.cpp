#include<iostream>

using namespace std;

int minDays(int S, int N, int M)
{
    int sunday = S/7;
    int buyingDay = S - sunday;
    int totalFood = S*M;
    int ans = 0;

    if(totalFood % N == 0)
    {
        ans = totalFood/N;
    }
    else
    {
        ans = totalFood/N + 1;
    }

    if(ans <= buyingDay)
    {
        return ans;
    }
    else
    {
        return -1;
    }
}

int main()
{
    int S = 10, N = 16, M = 2;
    cout<<minDays(S, N, M)<<endl;
    return 0;
}