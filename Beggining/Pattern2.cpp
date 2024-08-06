#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int i = 1;
    while (i <= n)
    {
        int j = 1;
        while (j <= n - i + 1)
        {
            cout << j;
            j++;
        }

        int k = i - 1;
        while (k)
        {
            cout << "**";
            k--;
        }
        // int l = i- 1;
        // while (l)
        // {
        //     cout << "*";
        //     l--;
        // }
        int m = n - i + 1;
        while (m)
        {
            cout << m;
            m--;
        }

        cout << endl;
        i++;
    }
}