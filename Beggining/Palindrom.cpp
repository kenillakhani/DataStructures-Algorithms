#include<iostream>
using namespace std;

char lowcase(char c)
{
    if(c>='A' && c<='Z')
        return c+'a'-'A';
    else  
        return c;
        
}
int palindrome(char name[],int n)  
{
    int i=0,j=n-1;
    while(i<j)
    {
        if(lowcase(name[i])!=lowcase(name[j]))
            return 0;
        i++;
        j--;

    while(!(lowcase(name[i])>='a' && lowcase(name[i])<='z' || name[i]>='1' && name[i]<='9'))
        i++;
    while(!(lowcase(name[j])>='a' && lowcase(name[j])<='z' || name[j]>='1' && name[j]<='9'))
        j--;
    }
    return 1;
}

int main()
{
    char name[100];
    cin.getline(name,100);
    int n=0;
    while(name[n]!='\0')
        n++;

    if(palindrome(name,n))
        cout<<"Palindrome\n";

    else
        cout<<"Not Palindrome\n";

    return 0;
}