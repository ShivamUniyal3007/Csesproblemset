// dp[i][j] denotes the total paths to reach n,n from i,j
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int numpaths(int i, int j, vector<string> &grid, vector<vector<int>> &dp)
{
    int n = grid.size();
    if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] == '*')
    {
        return 0;
    }
    if (dp[i][j] != -1)
        return dp[i][j];
    if (i == n - 1 && j == n - 1)
    {
        return 1;
    }
    int path1 = numpaths(i + 1, j, grid, dp);
    int path2 = numpaths(i, j + 1, grid, dp);

    return dp[i][j] = (path1 + path2) % 1000000007; // Modulo to prevent overflow
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<string> grid(n);
    vector<vector<int>> dp(n, vector<int>(n, -1)); 
    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }
    cout << numpaths(0, 0, grid, dp);
    return 0;
}

