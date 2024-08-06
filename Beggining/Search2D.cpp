// sorted in row and column vise then Search Algo.

/*
1  4  7  11  15
2  5  8  12  19
3  6  9  16  22
10 13 14 17  24
18 21 23 26  30
*/

#include <iostream>
using namespace std;

bool search(int a[][5], int target)
{
    int rowindex = 0;
    int colindex = 5 - 1;

    while (rowindex < 5 && colindex > -1)
    {
        int ele = a[rowindex][colindex];

        if (ele == target)
            return true;

        else if (ele < target)
            rowindex++;

        else
            colindex--;
    }
    return false;
}

int main()
{
    int a[5][5] = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
    int target;
    cout << "Enter Target: ";
    cin >> target;
    if (search(a, target))
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}