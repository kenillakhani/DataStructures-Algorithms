// Celebrity konws no one but everyone knows celebrity

#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int celebrity(vector<vector<int> > &M, int n)
{
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        s.push(i);
    }
    while (s.size() != 1)
    {
        int a = s.top();
        s.pop();

        int b = s.top();
        s.pop();

        if (M[a][b] == 1)
            s.push(b);

        else
            s.push(a);

        bool rowCount = true;
        int candidate = s.top();

        for (int i = 0; i < n; i++)
        {
            if (M[candidate][i] == 1)
            {
                rowCount = false;
                break;
            }
        }

        bool colCount = false;
        int oneCount = 0;

        for (int i = 0; i < n; i++)
        {
            if (M[i][candidate] == 1)
                oneCount++;
        }
        if (oneCount == n - 1)
            colCount = true;

        if (rowCount && colCount)
            return candidate;
    }

    return -1;
}

int main()
{
    vector<vector<int> > M;
    M.push_back(vector<int>());
    M.back().push_back(0);
    M.back().push_back(0);
    M.back().push_back(1);
    M.back().push_back(0);

    M.push_back(vector<int>());
    M.back().push_back(0);
    M.back().push_back(0);
    M.back().push_back(1);
    M.back().push_back(0);

    M.push_back(vector<int>());
    M.back().push_back(0);
    M.back().push_back(0);
    M.back().push_back(0);
    M.back().push_back(0);

    M.push_back(vector<int>());
    M.back().push_back(0);
    M.back().push_back(0);
    M.back().push_back(1);
    M.back().push_back(0);

    cout << "Celebrity is at position: ";
    cout << celebrity(M, 4);
    cout << endl;
    return 0;
}