// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;
// const int mod = 1e9+7;
// int numways(int i, int j, int x,vector<int> &values,vector<vector<int>> &dp)
// {
//    if(i==x) return 0;
//    if(i>x) return 0;

//    if(j==values.size()) return 0;
//     if(dp[i][j]!=-1) return dp[i][j];
//    int take = 1+numways(i+values[j], j, x, values,dp);
//    int not_take = numways(i,j+1,x,values,dp);

//    return dp[i][j] = (take+not_take)%mod;
// }
// int main(){
// ios_base::sync_with_stdio(false);
// cin.tie(NULL);
//     int n,x;
//     cin>>n>>x;
//     vector<int> values(n);
//     for(int i=0; i<n; i++)
//     {
//         cin>>values[i];
//     }
//     // sort(values.begin(), values.end());
//      vector<vector<int>> dp(x+10,vector<int>(n,-1));
//     cout<<  numways(0,0,x,values,dp);

//     return 0;
// }

// #include <iostream>
// #include <vector>
// using namespace std;

// const int mod = 1e9 + 7;

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int n, x;
//     cin >> n >> x;
//     vector<int> values(n);
//     for (int i = 0; i < n; i++) {
//         cin >> values[i];
//     }

//     vector<vector<int>> dp(x + 1, vector<int>(n + 1, 0));

//     // Base case: If the target sum is 0, there is only one way (empty set)
//     for (int j = 0; j <= n; j++) {
//         dp[0][j] = 1;
//     }

//     // Filling up the DP table
//     for (int i = 1; i <= x; i++) {
//         for (int j = n - 1; j >= 0; j--) {
//             dp[i][j] = dp[i][j + 1]; // Not taking the current coin
//             if (i >= values[j]) {
//                 dp[i][j] = (dp[i][j] + dp[i - values[j]][j]) % mod; // Taking the current coin
//             }
//         }
//     }

//     cout << dp[x][0] << endl;

//     return 0;
// }

// #include <iostream>
// #include <vector>
// using namespace std;

// const int mod = 1e9 + 7;

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int n, x;
//     cin >> n >> x;
//     vector<int> values(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> values[i];
//     }

//     vector<vector<int>> dp(x + 1, vector<int>(n + 1, 0));

//     // Base case: If the target sum is x, there is one way (no coins)
//     for (int j = 0; j <= n; j++)
//     {
//         dp[x][j] = 1;
//     }

//     for (int i = x - 1; i >= 0; i--)
//     {
//         for (int j = n - 1; j >= 0; j--)
//         {
//             int take;
//             if (i + values[j] <= x)
//             {
//                 take = dp[i + values[j]][j];
//             }
//             else
//             {
//                 take = 0;
//             }

//             int not_take = dp[i][j + 1];
//             dp[i][j] = (take + not_take) % mod;
//         }
//     }

//     cout << dp[0][0] << endl;

//     return 0;
// }


#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fr(a,b) for(int i = a; i < b; i++)
#define rep(i,a,b) for(int i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
 
 
int main() {
   fast_io;
   ll t,n,m,x,i,j,k,q;
   //cin >> t;
   t = 1;
   while(t--)
   {
        cin >> n >> x;
        vector<int> v(n+1);
        fr(1,n+1)
            cin >> v[i];
        int dp[n+1][x+1];
 
        for(int i = 1; i <= n; i++)
        {
                for(int sum = 0; sum <= x; sum++)
                {
                    if(sum == 0)
                        dp[i][sum] = 1;
                    else
                    {
                        int op1 = (v[i] > sum) ? 0 : dp[i][sum - v[i]];
                        int op2 = (i == 1) ? 0 : dp[i-1][sum];
                        dp[i][sum] = (op1 + op2) % mod;
                    }
                }
        }
 
        cout << dp[n][x];
   }
   return 0;
}