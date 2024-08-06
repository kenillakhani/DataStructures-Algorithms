// If any Permutation of s1 is subset of s2 then return True.

#include<iostream>
using namespace std;

int isEqual(int count[],int count2[])
{
    for(int i=0;i<26;i++)
    {
        if(count[i]!=count2[i])
            return 0;
    }
    return 1;
}

int PerInString(string s1,string s2)
{
    int count[26] = {0};
    for(int i=0;i<s1.length();i++)
    {
        int index = s1[i]-'a';
        count[index]++;
    }

    int k = s1.length();
    int i=0;
    int count2[26] = {0}; 
    while(i<k && i<s2.length())
    {
        int index = s2[i]-'a';
        count2[index]++;
        i++;
    }

    if(isEqual(count,count2))
        return 1;
    
    else
    {

        while(i<s2.length())
        {
            
            int index = s2[i]-'a';
            count2[index]++;
            index = s2[i-k]-'a';
            count2[index]--;    

            if(isEqual(count,count2))
                return 1;
            else
                i++;
        }
    }
    return 0;
}

int main()
{
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);

    if(PerInString(s1,s2))
        cout<<"True\n";
    else
        cout<<"False\n";

    return 0;
}