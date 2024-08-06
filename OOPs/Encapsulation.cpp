/*
Wrapping up Data member & funtion
All private -> Fully encapsulated Class

Advantge:
Information Hiding / Data Hiding -> Security ^
Class can be marked as -> read only
Code Reusability
Unit Testing
*/

#include<iostream>
using namespace std;

class Student{

    private:
    string name;
    int age;
    int height;

    private:
    int getAge(){
        return this->age;
    }

};
int main()
{
    Student first;
    cout<<"Everything Okay.\n";
    return 0;
}