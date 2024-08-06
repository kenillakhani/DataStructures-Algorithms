// gcd(a,b) = gcd(a%b,b) or gcd(a,b%a)
// gcd(a,b) = gcd(a-b,b) or gcd(a,b-a)

#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}  
int gcd2(int a,int b)
{
    if(a==0)
        return b;
    if(b==0)
        return a;
    if(a==b)
        return a;
    if(a>b)
        return gcd(a-b,b);
    return gcd(a,b-a);
} 

int main()
{
    int a,b;
    cin>>a>>b;
    cout << "GCD of " << a << " and " << b << " is " << gcd(a, b)<<endl;
    cout << "GCD of " << a << " and " << b << " is " << gcd2(a, b)<<endl;

    return 0;
}