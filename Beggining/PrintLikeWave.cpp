#include<iostream>
using namespace std;

void wave(int a[][4])
{
    for(int col=0;col<4;col++)
    {
        if(col%2==0)
        {
            for(int row=2;row>=0;row--)
                cout<<a[row][col]<<" ";
        }
        else
        {
            for(int row=0;row<3;row++)
                cout<<a[row][col]<<" ";
        }
    }
}
int main()
{
    int col = 4;
    int row = 3;
    int a[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};

    wave(a);
    return 0;
}
