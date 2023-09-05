
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
// int editdist(int i, int j, int n, int m,string &s1, string &s2, vector<vector<int>> &dp)
// {
//     if(i==n) return m-j;
//     if(j==m) return n-i;

//     if(dp[i][j]!=-1) return dp[i][j];

//     int ans = 0;
//     if(s1[i]==s2[j])
//     {
//         return dp[i][j] = editdist(i+1,j+1,n,m,s1,s2,dp);
//     }
//     else
//     {
//         int insertion = 1 + editdist(i,j+1,n,m,s1,s2,dp);
//         int deletion = 1 + editdist(i+1,j,n,m,s1,s2,dp);
//         int replace = 1 + editdist(i+1,j+1,n,m,s1,s2,dp);
//         ans = min({insertion,deletion,replace});
//         // ans = (1 + min({editdist(i,j+1,n,m,s1,s2,dp), editdist(i+1,j,n,m,s1,s2,dp),editdist(i+1,j+1,n,m,s1,s2,dp)}))%mod;

//     }
//     return dp[i][j]=ans;
// }


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s1;
    string s2;
    cin >> s1;
    cin >> s2;

    int n = s1.size();
    int m = s2.size();

    // vector<vector<int>> dp(n, vector<int>(m, -1));
    // cout<<editdist(0,0,n,m,s1,s2,dp);
    
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int j = 0; j <= m; j++) {
        dp[n][j] = m - j;
    }

    for (int i = 0; i <= n; i++) {
        dp[i][m] = n - i;
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            int ans = 0;
            if (s1[i] == s2[j]) {
                ans = dp[i + 1][j + 1];
            } else {
                int insertion = 1 + dp[i][j + 1];
                int deletion = 1 + dp[i + 1][j];
                int replace = 1 + dp[i + 1][j + 1];
                ans = min({insertion, deletion, replace});
            }
            dp[i][j] = ans;
        }
    }

    cout << dp[0][0];
    return 0;
}


