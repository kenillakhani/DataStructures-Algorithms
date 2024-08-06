#include<iostream>
using namespace std;

void Spiral(int a[][100],int col,int row)
{
    int frow =0;
    int lrow =row-1;
    int fcol =0;
    int lcol =col-1;

    int count=0;
    int total=col*row;

    while(count<total)
    {
        for(int i=fcol;i<=lcol && count<total ;i++)
        {
            cout<<a[frow][i]<<" ";
            count++;
        }
        frow++;

        for(int i=frow;i<=lrow && count<total ;i++)
        {
            cout<<a[i][lcol]<<" ";
            count++;
        }
        lcol--;

        for(int i=lcol;i>=fcol && count<total ;i--)
        {
            cout<<a[lrow][i]<<" ";
            count++;
        }
        lrow--;

        for(int i=lrow;i>=frow && count<total ;i--)
        {
            cout<<a[i][fcol]<<" ";
            count++;
        }
        fcol++;
    }
    cout<<endl;
}

int main()
{
    int row;
    int col;
    cin>>row;
    cin>>col;

   int a[100][100];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> a[i][j];
        }
    }

    Spiral(a,col,row);
    return 0;
}