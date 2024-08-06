/* You have been given a number of stairs. Initially, you are at the Oth stair,
and you need to reach the Nth stair. Each time you can either climb one step 
or two steps. You are supposed to return the number of distinct ways in which 
you can climb from the Oth step to Nth step.  */

// nth stair par n-1 / n-2 stair parthi aavi eke so f(n) = f(n-1) + f(n-2)
// 0th stair -> 1 way
// -1th stair -> 0 way

#include<iostream>
using namespace std;

int ways(int n)
{
    if(n==0)
        return 1;
    if(n<0)
        return 0;

    return ways(n-1) + ways(n-2);
}

int main()
{
    int n;
    cin>>n;
    cout<<ways(n)<<endl;   
    return 0;
}