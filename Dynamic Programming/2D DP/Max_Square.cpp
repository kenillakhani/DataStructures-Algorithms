#include <iostream>
#include <vector>

using namespace std;

int solve(vector<vector<int> > mat, int i, int j, int &maxi)
{
    if (i >= mat.size() || j >= mat[0].size())
    {
        return 0;
    }
    if (mat[i][j] == 0)
    {
        return 0;
    }

    int right = solve(mat, i, j + 1, maxi);
    int down = solve(mat, i + 1, j, maxi);
    int diag = solve(mat, i + 1, j + 1, maxi);

    int ans = 1 + min(right, min(down, diag));
    maxi = max(maxi, ans);
    return ans;
}

int solveMem(vector<vector<int> > &mat, int i, int j, int &maxi, vector<vector<int> > &dp)
{
    if (i >= mat.size() || j >= mat[0].size())
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    if (mat[i][j] == 0)
    {
        dp[i][j] = 0;
    }
    else
    {
    int right = solveMem(mat, i, j + 1, maxi, dp);
    int down = solveMem(mat, i + 1, j, maxi, dp);
    int diag = solveMem(mat, i + 1, j + 1, maxi, dp);

    int ans = 1 + min(right, min(down, diag));
    dp[i][j] = ans;
    maxi = max(maxi, ans);
    }
    return dp[i][j]; 
}

void solveTab(vector<vector<int> > &mat, int &maxi)
{
    int row = mat.size();
    int col = mat[0].size();

    vector<vector<int> > dp(row, vector<int>(col, 0));

    for(int i = row-1;i>=0;i--)
    {
        for(int j = col-1;j>=0;j--)
        {
            int right = (j+1<col)?dp[i][j+1]:0;
            int down = (i+1<row)?dp[i+1][j]:0;
            int diag = (i+1<row && j+1<col)?dp[i+1][j+1]:0;
            
            if(mat[i][j] == 0)
            {
                dp[i][j] = 0;
            }
            else
            {
                int ans = 1 + min(right, min(down, diag));
                dp[i][j] = ans;
                maxi = max(maxi, ans);
            }    
        }
    }
}

// Do space optimization in tabulation  

int maxSquare(int n, int m, vector<vector<int> > mat)
{
    // int maxi = 0;
    // solve(mat, 0, 0, maxi);
    // return maxi;

    int maxi = 0;
    vector<vector<int> > dp(n, vector<int>(m, -1));
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            solveMem(mat, i, j, maxi, dp);
        }
    }
    return maxi;

    // int maxi = 0;
    // solveTab(mat, maxi);
    // return maxi;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int> > mat(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }
    cout << maxSquare(n, m, mat) << endl;
}