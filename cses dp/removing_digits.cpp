#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minsteps(int i, vector<int> &dp) {
    if (i == 0) return 0;
    if (dp[i] != -1) return dp[i];

    int ans = INT_MAX;
    int num = i;
    while (num > 0) {
        int digit = num % 10;
        if (digit != 0) {
            int val = minsteps(i - digit, dp);
            ans = min(ans, val + 1);
        }
        num /= 10;
    }
    return dp[i] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    cout << minsteps(n, dp);
    return 0;
}
