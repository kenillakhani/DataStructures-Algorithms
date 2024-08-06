#include <iostream>
using namespace std;

int tsqrt(int s, int e, int n)
{
    if (s > e)
        return s;

    int mid = s + (e - s) / 2;

    if (mid * mid == n)
        return mid;

    else if (mid * mid < n)
    {
        if ((mid + 1) * (mid + 1) > n)
            return mid;

        else
            return tsqrt(mid + 1, n, n);
    }
    else

        return tsqrt(s, mid - 1, n);
}
double psqrt(int n)
{
    double temp = tsqrt(1, n, n);
    double fact = 1;
    for (int j = 0; j < 4; j++)
    {
        fact = fact / 10;
        for (long double i = temp; i * i < n; i += fact)
        {
            temp = i;
        }
    }
    return temp;
}

int main()
{
    int n;
    cin >> n;
    cout << psqrt(n) << endl;
    return 0;
}