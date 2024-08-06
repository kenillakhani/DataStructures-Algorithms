
#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    int a = 20;

    while (a)
    {
        switch (a)
        {
        case 10:
            cout << "Hello" << endl;
            continue;
        case 20:
            cout << "World" << endl;
            break;
        default:
            cout << "Default" << endl;
            break;
        }
        exit(0);
        continue;
    }
    cout << "Bye" << endl;
}
