#include<iostream>
using namespace std;

void print(int *p)
{
    cout<<*p<<endl;
}
void update(int *p)
{
    (*p)++;
}

int main()
{
    int value = 5;
    int *p = &value;

    print(p);
    update(p);
    print(p);

    return 0;
}
