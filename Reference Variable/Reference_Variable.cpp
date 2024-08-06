#include<iostream>
using namespace std;

// Reference var. means one variable but two different names.
int main()
{
    int i = 8;
    int &j = i;

    cout<<i<<" "<<j<<endl;
    i++;
    cout<<i<<" "<<j<<endl;
    j++;
    cout<<i<<" "<<j<<endl;

    return 0;
}