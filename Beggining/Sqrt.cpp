#include <iostream>
using namespace std;
int mySqrt(int n)
{
    if (n == 0)
        return 0;
    int i = 0;
    for (i = 1; i <= 46340; i++)
    {
        if (i * i == n)
            return i;
        else if (i * i > n)
            return i - 1;
    }
    return i - 1;
}
int main()
{
    cout << mySqrt(INT32_MAX);
    return 0;
}