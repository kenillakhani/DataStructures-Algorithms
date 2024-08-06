#include <iostream>
using namespace std;
double myPow(double x, int n)
{
    if (n == 0)
        return 1;

    if (n == 1)
        return x;

    if (n == INT_MIN)
        return 1 / (x * myPow(x, -(n + 1)));

    else if (n < 0)
        return 1 / myPow(x, -n);

    if (n % 2 == 0)
        return myPow(x * x, n / 2);
        
    else
        return x * myPow(x * x, n / 2);
}
int main()
{
    cout << myPow(2, INT_MIN) << endl;
    return 0;
}