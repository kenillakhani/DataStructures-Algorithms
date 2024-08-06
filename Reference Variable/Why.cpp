#include<iostream>
using namespace std;

// Pass by Reference
void update(int &p)  // n vali location ne aa fnction mate p name mali jaay so changes can be done on n.
{
    p++;
}

int main()
{
    int n=5;
    cout<<"Before: "<<n<<endl;
    update(n);
    cout<<"After: "<<n<<endl;   
    return 0;
}