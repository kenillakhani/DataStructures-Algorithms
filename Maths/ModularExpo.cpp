// We have to find the value of a^b mod c
// Properties of Modular Exponentiation

// 1. (a*b)%c = ((a%c)*(b%c))%c
// 2. (a^b)%c = ((a%c)^b)%c

// Time Complexity: O(logb)

// Constraints:
// 0 <= a,b,c <= 10^9

#include<iostream>
using namespace std;
int module(int a,int b,int c)
{
    int res=1;
    while(b>0)
    {
        // Odd
        if(b&1)
        {
            res = ( 1LL * (res%c)*(a%c))%c;  // Overflow so use property 1
        }

        a=( 1LL * (a%c)*(a%c))%c;  // If m is samll then Overflow So long long se Typecast karna padega in both Cases

        b=b>>1; // b=b/2
    }
    return res;
}
int main()
{
    int a,b,c;
    cout<<"Enter the value of a,b,c:";
    cin>>a>>b>>c;

    cout<<"Ans: "<<module(a,b,c)<<endl; 

    return 0;
}