#include <iostream>
using namespace std;
/*
    if n = 5 then in binary 101 so output is complement (010) = 2 ..
*/
int bitwiseComplement(int num)
{
    int x=num;
    int mask=0;
    
        if(x==0)
            return 1;
            
        while(x!=0)
        {
            mask=mask<<1;
            mask=(mask|1);
            x=x>>1;
        }
    
        return (~num) & mask;
        
}
int main()
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << bitwiseComplement(n) << endl;
}