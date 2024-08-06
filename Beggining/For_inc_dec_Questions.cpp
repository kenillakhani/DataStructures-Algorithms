#include <iostream>
using namespace std;

int main()

{

    // 1
        int a, b = 1;
        a = 10;
        if (++a)
            cout << b;
        else
            cout << ++b;

    // 2
        int a = 1;
        int b = 2;
        if (a-- > 0 && ++b > 2)
        {
            cout << "Stage1 - Inside If ";
        }
        else
            cout << "Stage2 - Inside else ";

        cout << a << " " << b << endl;

    // 3
        int a = 1;
        int b = 2;

        if (a-- > 0 || ++b > 2)
        {
            cout << "Stage1 - Inside If ";
        }
        else
            cout << "Stage2 - Inside else ";

        cout << a << " " << b << endl;

    // 4
        int number = 3;
        cout << (25 * (++number));

    // 5
        int a = 1;
        int b = a++ ;
        int c = ++a;
        cout << b;
        cout << c;

    // 6
        for (int i = 0; i <= 5; i ++)
        {
            cout<< i << " ";
            i++;
        }

    // 7
        for (int i = 0; i <= 5; i--)
        {
            cout << i << " ";
            i++;
        }

    // 8
        for (int i = 0; i < 5; i++)
        {
            for (int j = i; j <= 5; j++)
            {
                cout << i << " " << j << endl;
            }
        }

    // 9
        for (int i= 0; i <= 15; i += 2)
        {
            cout << i << " " ;
            if (i & 1)
            {
                continue;
            }
            i++;
        }

    // 10
    for (int i = 0; i < 5; i++)
    {
        for (int j = i; j <= 5; j++)
        {
            if (i + j == 10)
            {
                break;
            }
            cout << i << " " << j << endl;
        }
    }
}
