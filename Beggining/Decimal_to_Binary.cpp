#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    int ans = 0;

    // 1
    /*
    while (n != 0)
    {
        int rem = n % 2;
        ans = ans * 10 + rem;
        n /= 2;
    }
*/
    // 2
    int i = 0;
    while (n != 0)
    {
        int bit = (n & 1);
        cout << bit;
        ans = ans + pow(10, i) * bit;
        n = n >> 1;
        i++;
    }
    cout << ans << endl;
}