#include <iostream>
#include <string.h>
using namespace std;

class Hero
{
public:
    int health;
    char level;
    char *name;

    Hero()
    {
        name = new char(100);
    }

    void setHealth(int h)
    {
        health = h;
    }
    void setLevel(char l)
    {
        level = l;
    }
    void setName(char *n)
    {
        strcpy(this->name, n);
    }
    void print()
    {
        cout << endl;
        cout << "Name: " << name << ", ";
        cout << "Health: " << health << ", ";
        cout << "Level: " << level << ", ";
        cout << endl;
    }

    Hero(Hero &temp)
    {
        cout << "Copy Constructor Called" << endl;
        this->health = temp.health;
        this->level = temp.level;
        strcpy(this->name, temp.name); // deep copy
        // this->name = temp.name; shallow copy ma aavi rite hoy
    }
};

int main()
{
    Hero h1;
    h1.setHealth(88);
    h1.setLevel('D');
    char name[7] = "Babbar";
    h1.setName(name);
    h1.print();

    Hero h2(h1); // Shallow Copy jo copy constructor define karya vagar kariye to.
    h2.print();

    h1.name[0] = 'G';
    h1.print();

    h2.print();

    return 0;
}