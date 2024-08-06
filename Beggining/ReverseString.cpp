#include <iostream>
using namespace std;
char name[100];

void reverse(int n)
{
    int i = 0, j, l = 0;
    while (i < n)
    {
        while (i<n && name[i] != ' ')
            i++;

        j = i-1;
        while (l < j)
        {
            char temp = name[l];
            name[l] = name[j];
            name[j] = temp;
            l++;
            j--;
        }
        l = i + 1;
        i++;
    }
}
int main()
{
    cin.getline(name, 100);
    int n = 0;
    while (name[n] != '\0')
        n++;

    reverse(n);
    cout << name << endl;
    return 0;
}