#include<iostream>
using namespace std;

void update(int** p)
{
   // p = p+1;
    // kuch change hoga? - NO

   // *p = *p+1;
    // kuch change hoga? - Value of p will be changed

    **p = **p+1;
    // kuch change hoga? - Value of i will be changed

}

int main()
{
    int i=5;
    int* p = &i;
    int** p2 = &p;

    cout<<p<<" - "<<*p2<<" - "<<&i<<endl;
    
    cout<<&p<<" - "<<p2<<endl;

    cout<<i<<" - "<<*p<<" - "<<**p2<<endl;

    cout<<"Before"<<endl;
    cout<<i<<" "<<p<<" "<<p2<<endl;

    update(p2);

    cout<<"After"<<endl;
    cout<<i<<" "<<p<<" "<<p2<<endl;

    return 0;
}