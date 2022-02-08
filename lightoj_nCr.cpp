#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[10001][10001];
ll nCr(ll n,ll r){
   if(n==r) return 1;
   if(r==0) return 1;
   if(r==1) return n;
   if(dp[n][r]!=-1) return dp[n][r];
   dp[n][r]=nCr(n-1,r)+nCr(n-1,r-1);
   return dp[n][r];
}
int main()
{
    int t,ca=0;
    cin>>t;
    while(t--){
        ll n,r;
        memset(dp,-1,sizeof(dp));
        scanf("%lld lld",&n,&r);
        ll ans=nCr(n,r);
        cout<<ans<<endl;
    }
}
