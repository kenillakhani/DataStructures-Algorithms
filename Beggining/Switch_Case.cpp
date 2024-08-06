#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the Money you have: ";
    cin >> n;
    int no;
    switch (1)
    {
    case 1:
        no = n / 100;
        n = n % 100;
        cout << no << " 100Rs.\n ";

    case 2:
        no = n / 50;
        n = n % 50;
        cout << no << " 50Rs.\n ";

    case 3:
        no = n / 20;
        n = n % 20;
        cout << no << " 20Rs.\n ";

    case 4:
        no = n / 1;
        cout << no << " 1Rs.\n ";
    }
    return 0;
}