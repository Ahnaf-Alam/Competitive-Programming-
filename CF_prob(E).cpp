#include<bits/stdc++.h>
using namespace std;
#define mod  998244353
typedef long long ll;
vector<ll>v;
ll powd(ll n,ll p){
    if(p==0) return 1;
    if(p%2==0){
        ll ret=powd(n,p/2);
        return ((ret%mod)*(ret%mod))%mod;
    }
    else return(n%mod*(powd(n,p-1))%mod);
}
int main()
{
    ll n,tt=1,tmp;
    cin>>n;
    for(int i=n;i>=1;i--){
        if(i==2) cout<<180<<" ";
        else if(i==1) cout<<10<<" ";
        else{
        tmp=(((9*powd(10,i-2))*2) + ((9*9*powd(10,i-3)*(i-2))%mod))*10;
        tmp%=mod;
        cout<<tmp<<" ";
        }
    }
}
