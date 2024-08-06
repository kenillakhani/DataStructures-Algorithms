#include <iostream>
using namespace std;
int main()
{
    // case 1
    // while (1)  // loop 1 vaar run thay pachi 2nd time run thay ena pela i free thai gayo hoy so it can't crash the program.
    // {
    //     int i = 5;
    // }

    // case 2
    while (1) // stack ma create thayelu pointer to free thai jaashe but heap ma navo navo int banto jaashe so program crash.
    {
        int *p = new int[1000000];
    }
    return 0;
}