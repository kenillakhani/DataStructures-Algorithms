#include <iostream>
using namespace std;

class Solution
{
private:
    bool isPossible(int x, int y, vector<vector<int> > &m, vector<vector<int> > &visited, int n)
    {
        if (x < n && x >= 0 && y < n && y >= 0 && visited[x][y] == 0 && m[x][y] == 1)
            return true;
        return false;
    }

    void solv(vector<vector<int> > &m, int n, int x, int y, vector<vector<int> > &visited, string path, vector<string> &ans)
    {
        if (x == n - 1 && y == n - 1)
        {
            ans.push_back(path);
            return;
        }

        visited[x][y] = 1;

        int newx, newy;

        // Right
        newx = x;
        newy = y + 1;
        if (isPossible(newx, newy, m, visited, n))
        {
            path.push_back('R');
            solv(m, n, newx, newy, visited, path, ans);
            path.pop_back();
        }

        // Down
        newx = x + 1;
        newy = y;
        if (isPossible(newx, newy, m, visited, n))
        {
            path.push_back('D');
            solv(m, n, newx, newy, visited, path, ans);
            path.pop_back();
        }

        // Up
        newx = x - 1;
        newy = y;
        if (isPossible(newx, newy, m, visited, n))
        {
            path.push_back('U');
            solv(m, n, newx, newy, visited, path, ans);
            path.pop_back();
        }

        // Left
        newx = x;
        newy = y - 1;
        if (isPossible(newx, newy, m, visited, n))
        {
            path.push_back('L');
            solv(m, n, newx, newy, visited, path, ans);
            path.pop_back();
        }

        visited[x][y] = 0;
    }

public:
    vector<string> findPath(vector<vector<int> > &m, int n)
    {
        vector<string> ans;
        if (m[0][0] == 0)
            return ans;

        string path = "";

        // Initialize a separate visited matrix
        vector<vector<int> > visited(n, vector<int>(n, 0));

        solv(m, n, 0, 0, visited, path, ans);
        sort(ans.begin(), ans.end());

        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int> > m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}