#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll>v;
int main()
{
    ll a,b,tmp,mn,lcm,g,ans=0,x,y;
    scanf("%lld %lld",&a,&b);
    tmp=abs(a-b);
    for(int i=1;i*i<=tmp;i++){
        if(tmp%i==0){
            v.push_back(i);
            if(i*i!=tmp){
                v.push_back(tmp/i);
            }
        }
    }
    sort(v.begin(),v.end());
    lcm=1e18+1;
    for(int i=0;i<v.size();i++){
       if(a%v[i]!=b%v[i]) continue;
     if(a%v[i]==0){
        g=__gcd(a,b);
        mn=(a*b)/g;
        if(mn<lcm){
            lcm=mn;
            ans=0;
        }
    }
    else{
        x=v[i]-a%v[i]+a;
        y=v[i]-b%v[i]+b;
        g=__gcd(x,y);
        mn=(x*y)/g;
        if(mn<lcm){
            lcm=mn;
            ans=v[i]-(a%v[i]);
        }
    }
    }
    cout<<ans<<endl;
}
