// // dp[i][j] represents number of pages that I can buy if i consider books from 0 to ith book  with a alloted amount of j

// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;
// const int mod = 1e9+7;

// int numpages(int i, int j, vector<int> &cost, vector<int> &pages, vector<vector<int>> &dp)
// {
//     if(i == 0 || j <= 0) return 0;

//     if(dp[i][j] != -1) return dp[i][j];
    
//     int not_take = numpages(i - 1, j, cost, pages, dp);
    
//     if (cost[i - 1] > j) {
//         return dp[i][j] = not_take;
//     }
    
//     int take = pages[i - 1] + numpages(i - 1, j - cost[i - 1], cost, pages, dp);

//     return dp[i][j] = max(take, not_take);
// }

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
    
//     int n, x;
//     cin >> n >> x;
    
//     vector<int> cost(n);
//     for(int i = 0; i < n; i++)
//     {
//         cin >> cost[i];
//     }
    
//     vector<int> pages(n);
//     for(int i = 0; i < n; i++)
//     {
//         cin >> pages[i];
//     }
    
//     vector<vector<int>> dp(n + 1, vector<int>(x + 1, -1));
//     cout << numpages(n, x, cost, pages, dp);
    
//     return 0;
// }





//Tabulation
#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, x;
    cin >> n >> x;
    
    vector<int> cost(n);
    for(int i = 0; i < n; i++) {
        cin >> cost[i];
    }
    
    vector<int> pages(n);
    for(int i = 0; i < n; i++) {
        cin >> pages[i];
    }
    
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
    
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= x; j++) {  // Changed j = x to j <= x
            int not_take = dp[i-1][j];
            int take = 0;
            if(cost[i-1] <= j) {  // Corrected the condition
                take = dp[i-1][j-cost[i-1]] + pages[i-1];
            }
            dp[i][j] = max(take, not_take);
        }
    }
    cout << dp[n][x];
    return 0;
}

