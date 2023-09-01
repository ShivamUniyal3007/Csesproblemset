#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9+7;
int totalways(ll i, vector<ll> &values, vector<ll> &dp)
{
    if(i==0) return 1;

    ll total = 0;
    if(dp[i]!=-1) return dp[i];
    for(ll k = 0; k<values.size(); k++)
    {
        if(i-values[k]>=0)
        {
            total = (total+ totalways(i-values[k],values,dp))%mod;
        }
    }
    dp[i] = total;
    return dp[i]%mod;
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    ll int n,x;
    cin>>n>>x;
    vector<ll> dp(x+1,-1);
    vector<ll> values(n);
    for(ll i=0; i<n; i++)
    {
        cin>>values[i];
    }
    cout<<totalways(x,values,dp);
    return 0;
}