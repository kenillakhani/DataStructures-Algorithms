// In-place solution Required..

// For rotation of matrix by 90 degree 1st we do transpose of given matrix and then reverse each row and we get the rotated matrix.

#include<iostream>
using namespace std;

void rotate90(int a[][100],int row, int col)
{
    // Transpose of Given Matrix
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<=i;j++)
        {
            swap(a[i][j],a[j][i]);
        }
    }

    // Reverse each Row
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col/2;j++)
        {
            swap(a[i][j],a[i][col-1-j]);
        }
    }

    // Print Matrix
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

}

int main()
{
    int row,col;
    int a[100][100];
    cin>>row>>col;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
            cin>>a[i][j];
    }
    cout<<endl;

    rotate90(a,row,col);
    return 0;
}