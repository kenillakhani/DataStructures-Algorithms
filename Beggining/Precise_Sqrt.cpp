#include <iostream>
using namespace std;
int tempsq(int n)
{
    int s = 0;
    int e = n;
    int mid = s + (e - s) / 2;
    int ans = 0;
    while (s < e)
    {
        if (mid * mid == n)
            return mid;

        else if (mid * mid < n)
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}
double presise(int n, int p)
{
    double t = tempsq(n);
    double fact = 1;
    for (int i = 0; i < p; i++)
    {
        fact = fact / 10;
        for (long double j = t; j * j < n; j += fact)
        {
            t = j;
        }
    }
    return t;
}
int main()
{
    int n;
    cin >> n;

    cout << presise(n, 3)<<endl;
    return 0;
}