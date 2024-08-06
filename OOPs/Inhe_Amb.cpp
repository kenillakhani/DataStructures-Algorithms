#include <iostream>
using namespace std;
class A
{
public:
    void func()
    {
        cout << "I am A." << endl;
    }
};
class B
{
public:
    void func()
    {
        cout << "I am B." << endl;
    }
};
class C : public A, public B
{
};
int main()
{
    C obj;
    // obj.func(); // Ambiguity (kaya claas ni methode use karvi ??)
    obj.A::func(); // Scope resolution operator

    return 0;
}