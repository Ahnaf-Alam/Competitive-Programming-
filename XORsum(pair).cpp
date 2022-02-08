#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
ll a[300001];
int main()
{
    ll n,one=0,zero=0,ans=0,d=1;
    scanf("%lld",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(int i=0;i<60;i++){
        ll bit = 1LL<<i;
        one=zero=0;
        for(int j=1;j<=n;j++){
            if(a[j] & bit ){
                one++;
            }
            else zero++;
        }
       ans+=(bit%mod)*((one*zero)%mod)%mod;
    }
    printf("%lld\n",ans%mod);
}
