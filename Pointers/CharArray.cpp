#include<iostream>
using namespace std;

int main()
{
    int arr[5] = {1,2,3,4,5};
    char ch[6] = "abcde";

    cout<<arr<<endl;
    cout<<ch<<endl; // Prints entire String

    char *c = &ch[0];
    cout<<c<<endl; // Prints entire String

    char temp = 'v';
    char *te = &temp;

    cout<<te<<endl;

    char *cha = "abcde";  // Bahut Bhayankar --> Nahi Karna!!
    cout<<cha<<endl;
    return 0;
}
  