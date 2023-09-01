#include<iostream>
#include<bits/stdc++.h>
#define int long long
const int MOD = 1e9+7;
using namespace std;

int numways(int i,vector<int> &dp)
{
    if(i==0) return 1;
    if(i<0) return 0;
    if(dp[i]!=-1) return dp[i];

dp[i]=0;
    for(int k = 1; k<=6; k++)
    {
        dp[i]=(dp[i]+numways(i-k,dp))%MOD;
    }
    return dp[i]%MOD;
}
int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> dp(n+1,-1);
    int ans =  numways(n,dp);
    cout<<ans;
    return 0;
}