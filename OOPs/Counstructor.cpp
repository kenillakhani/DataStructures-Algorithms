#include <iostream>
using namespace std;

class Hero
{
public:
    
    int health;
    char level;
    
    Hero()
    {
        cout << "Counstructor called." << endl;
        cout << "This: " << this << endl;
    }
    Hero(int health)
    {
        this->health = health;
    }
    Hero(int health, char level)
    {
        this->health = health;
        this->level = level;
    }
    Hero(Hero &h) // default hoy j...
    {
        cout << "Copy Constructor Called" << endl;
        this->health = h.health;
        this->level = h.level;
    }

};
int main()
{
    // static
    Hero ram;
    cout << "Address of Ram: " << &ram << endl;

    // dynamic
    Hero *h = new Hero;
    cout << "Address of h: " << h << endl;

    Hero *h1 = new Hero(100);
    cout << "Address of h1: " << h1 << endl;
    cout << "Health: " << h1->health << endl;

    Hero h2(100, 'A');
    cout << "Address of h2: " << &h2 << endl;
    cout << "Health: " << h2.health << endl;
    cout << "Level: " << h2.level << endl;

    // copy constructor
    Hero R(h2);
    cout << "Health: " << R.health << endl;
    cout << "Level: " << R.level << endl;

    return 0;
}