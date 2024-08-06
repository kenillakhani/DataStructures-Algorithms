#include<iostream>
using namespace std;

// s -> daabcbaabcbc
// part -> abc

// s -> dabaabcbc
// s -> dababc
// s -> dab

int main()
{
    string s,part;
    cout<<"Enter the string: ";
    getline(cin,s);
    cout<<"Enter the part to be removed: ";
    getline(cin,part);

    while(s.length()> s.find(part) && s.length() != 0)
    {
        s.erase(s.find(part), part.length());
    }

    cout<<"The string after removing the part is: "<<s<<endl;

    return 0;
}