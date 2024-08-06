#include <iostream>
using namespace std;

void reverse(string &s, int i, int n)
{
    if (i > n)
        return;

    swap(s[i], s[n]);
    i++;
    n--;
    reverse(s, i, n);
}

int main()
{
    string s;
    cin >> s;
    int n = s.length();
    reverse(s, 0, n - 1);
    cout << s << endl;

    return 0;
}