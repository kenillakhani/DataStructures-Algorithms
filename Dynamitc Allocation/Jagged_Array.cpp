#include<iostream>
using namespace std;
int main()
{
    // Creating Array
    int row;
    cout<<"Enter Number of rows: ";
    cin>>row;
    int* cols = new int[row];
    int** array = new int* [row];

    for(int i=0;i<row;i++)
    {
        cout<<"Enter Columns in Row "<<i+1<<": ";
        cin>>cols[i];
        array[i] = new int [cols[i]];
    }

    // Taking Input
    for(int i=0;i<row;i++)
    {
        cout<<"Enter elements in Row "<<i+1<<": ";
        for(int j=0;j<cols[i];j++)
        {
            cin>>array[i][j];
        }
    }

    // Printing Output
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<cols[i];j++)
        {
            cout<<array[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}