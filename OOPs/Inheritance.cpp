/*
Types of Inheritance:
1. Single Inheritance
    A->B

2. Multiple Inheritance
    A->C
    B->C
    class C: public B, public A

3. Multilevel Inheritance
    A->B->C


4. Hierarchical Inheritance
    A->B
    A->C

5. Hybrid Inheritance
    A->B
    A->C
    B->D
    C->D
    Mix....

*/



#include <iostream>
using namespace std;

class Human
{

public:
    int height;
    int weight;
    int age;

public:
    int getAge()
    {
        return this->age;
    }
    void setWeight(int w)
    {
        this->weight = w;
    }
};

// Protected -> self and child class can access the data
// Private -> only self can access the data
// Public -> everyone can access the data

/*
Access Specifier	Public Derivation	Protected Derivation	Private Derivation
Public	            Public	            Protected	            Inaccessible
Protected	        Protected	        Protected	            Inaccessible
Private	            Private	            Private	                Inaccessible
*/

class Male : public Human
{
public:
    string color;

    void sleep()
    {
        cout << "Male Sleeping" << endl;
    }
};

int main()
{
    Male obj1;

    cout << obj1.age << endl;
    cout << obj1.height << endl;
    cout << obj1.weight << endl;
    cout << obj1.color << endl;
    obj1.sleep();
    obj1.setWeight(67);
    cout << obj1.weight << endl;


    return 0;
}