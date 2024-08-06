#include<iostream>
using namespace std;

int& func(int n)
{
    int a = 10;
    int& ans = a;
    return ans; // Aaya a no reference variable return karyo 6e but a nu existance function execute thay etle puru thay jaay so e location par bijo koi variable store thay to ans ene reference karva mande so it is anb bad practise..
}

int* fun(int n)
{
    int* ptr = &n;
    return ptr;  // n nu existance aa function execute thay pachi puru thay jaay ane enu address return karyu hovathi e address par bija koi variable ni valur pan store thai gai hoy so it is an bad practise..
}

int main()
{
    int n = 5;

    func(n);
    fun(n);   
    return 0;
}