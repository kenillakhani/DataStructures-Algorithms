/*
2 Types of Polymorphism:

1. Compile Time Polymorphism (Static Polymorphism)
    - Function Overloading
    - Operator Overloading

2. Run Time Polymorphism (Dynamic Polymorphism)
    Rules:
    - Inheritance
    - Function Overriding ( Name and Arguments have to be same )

*/

#include <iostream>
using namespace std;
class A // Function Overloading
{
public:
    void sayHello()
    {
        cout << "Hello Kenil." << endl;
    }
    void sayHello(string name)
    {
        cout << "Hello " << name << "." << endl;
    }
    // khaali return type change karine function overloading nai thay.
};
class B // Operator Overloading
{
public:
    int a;
    int b;

public:
    int add()
    {
        return a + b;
    }
    void operator+(B &obj)
    {
        int val1 = this->a;
        int val2 = obj.a;
        cout << "Sum is: " << val2 - val1 << endl;
    }
    void operator()()
    {
        cout << "Me Bracket Hu.  " << this->a << endl;
    }
};
class Animal
{
public:
    virtual void speak()
    {
        cout << "Animal speaks." << endl;
    }
};
class Dog : public Animal
{
public:
    void speak() // Run time polymorphism
    {
        cout << "Dog barks." << endl;
    }
};
int main()
{
    A obj;
    obj.sayHello();
    obj.sayHello("Ken");
    B obja, objb;
    obja.a = 10;
    objb.a = 20;

    obja + objb;
    obja();
    objb();

    Dog d1;
    d1.speak();
    return 0;
}