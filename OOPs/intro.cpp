#include <iostream>
using namespace std;

class Hero
{
    // properties
    int health;
    char level;
};

int main()
{
    // Declaration
    Hero h1;
    cout << "Size: " << sizeof(h1) << endl;
    // if any variable isn't present in hero than size is 1 byte..
    return 0;
}