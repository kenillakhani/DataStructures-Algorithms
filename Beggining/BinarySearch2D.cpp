// if we convert 2D array to 1D then array is Sorted then we an apply this code.

#include <iostream>
using namespace std;

bool binary(int a[][100], int row, int col, int target)
{
    int start = 0;
    int end = row * col - 1;

    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        int ele = a[mid / col][mid % col];

        if (ele == target)
        {
            return true;
        }
        else if (ele < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }

        mid = start + (end - start) / 2;
    }
    return false;
}
bool linear(int a[][100],int row,int col,int target)
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(a[i][j]==target)
                return true;
        }
    }
    return false;
}

int main()
{
    int row, col, target;
    cin >> row >> col;
    int a[100][100];

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            cin >> a[i][j];
    }

    cout << "Enter Target: ";
    cin >> target;

    if (binary(a, row, col, target))
        cout << "Yes\n";
    else
        cout << "No\n";


    if (linear(a, row, col, target))
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}