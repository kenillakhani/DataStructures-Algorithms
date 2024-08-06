#include <iostream>
using namespace std;
class Hero
{
public:
    int health;
    char level;
    static int timeToComplete;

    Hero()
    {
        cout << "Counstructor called." << endl;
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

    // it can access only static member
    // this keyword no hoy
    // object creation no need
    static int ramdom()
    {
        return timeToComplete;
    }
};

int Hero::timeToComplete = 5;

int main()
{
    cout << Hero::timeToComplete << endl;
 
    Hero h1;

    cout << h1.timeToComplete << endl;

    Hero h2;

    h2.timeToComplete = 10;
    cout << h1.timeToComplete << endl;
    cout << h2.timeToComplete << endl;

    cout << Hero::ramdom() << endl;

    return 0;
}