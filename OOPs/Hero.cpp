#include <iostream>
using namespace std;

class Hero
{
    // properties
private:
    int health;

public:
    char level;

    // methods
    int getHealth()
    {
        return health;
    }

    void setHealth(int h)
    {
        health = h;
    }

    char getLevel()
    {
        return level;
    }

    void setLevel(char l)
    {
        level = l;
    }
};

int main()
{
    // Static Allocation
    Hero ramesh;

    // Dynamic Allocation

    // ramesh.health = 77;
    ramesh.level = 'A';

    // cout<<"Health is: "<<ramesh.health<<endl;
    cout << "Level is: " << ramesh.level << endl;

    ramesh.setHealth(89);
    cout << "Health is: " << ramesh.getHealth() << endl;

    Hero *suresh = new Hero;

    suresh->setHealth(67);
    suresh->level = 'B';

    cout<<"Health: "<<(*suresh).getHealth()<<endl;
    cout<<"Level: "<<(*suresh).level<<endl;

    cout<<"Health: "<<suresh->getHealth()<<endl;
    cout<<"Level: "<<suresh->level<<endl;

    return 0;
}