#include<iostream>
using namespace std;

class Hero
{
public:
    
    int health;
    char level;
    
    Hero()
    {
        cout << "Counstructor called." << endl;
    }
    ~Hero()
    {
        cout << "Destructor called." << endl;
    }
   

};

int main()
{
    Hero h1; // auto destructor called
    Hero * h2 = new Hero(); // manually called
    delete h2;
    
    return 0;
}