
// #include <iostream>
// #include <vector>
// #include <cstring>
// using namespace std;
// const int MOD = 1e9 + 7;

// int numWays(int n, int m, vector<int>& arr, vector<vector<int>>& dp, int i, int x) {
//     if (i == 0) {
//         // Base case: There is only one way to fill the first element.
//         if (arr[0] == 0 || arr[0] == x) return 1;
//         return 0;
//     }

//     if (dp[i][x] != -1) return dp[i][x];

//     int ways = 0;
//     if (arr[i] == 0 || arr[i] == x) {
//         if (x > 1) ways = (ways + numWays(n, m, arr, dp, i - 1, x - 1)) % MOD;
//         ways = (ways + numWays(n, m, arr, dp, i - 1, x)) % MOD;
//         if (x < m) ways = (ways + numWays(n, m, arr, dp, i - 1, x + 1)) % MOD;
//     }

//     return dp[i][x] = ways;
// }

// int main() {
//     int n, m;
//     cin >> n >> m;
//     vector<int> arr(n);

//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }

//     vector<vector<int>> dp(n, vector<int>(m + 1, -1));
//     int ans = 0;

//     for (int x = 1; x <= m; x++) {
//         ans = (ans + numWays(n, m, arr, dp, n - 1, x)) % MOD;
//     }

//     cout << ans << endl;

//     return 0;
// }






#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int MOD = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<vector<int>> dp(n, vector<int>(m + 1, 0));

    // Initialize the base case
    if (arr[0] == 0) {
        for (int x = 1; x <= m; x++) {
            dp[0][x] = 1;
        }
    } else {
        dp[0][arr[0]] = 1;
    }

    for (int i = 1; i < n; i++) {
        for (int x = 1; x <= m; x++) {
            if (arr[i] == 0 || arr[i] == x) {
                dp[i][x] = dp[i - 1][x];
                if (x > 1) dp[i][x] = (dp[i][x] + dp[i - 1][x - 1]) % MOD;
                if (x < m) dp[i][x] = (dp[i][x] + dp[i - 1][x + 1]) % MOD;
            }
        }
    }

    int ans = 0;
    for (int x = 1; x <= m; x++) {
        ans = (ans + dp[n - 1][x]) % MOD;
    }

    cout << ans << endl;

    return 0;
}

