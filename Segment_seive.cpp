#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define  prec(n)        fixed<<setprecision(n)
#define  optimize       ios::sync_with_stdio(0); cin.tie(0);
#define  PI             acos(-1.0)
#define  RESET(a, b)    memset(a, b, sizeof(a))
#define  pb             push_back
#define  sz(v)          v.size()
#define  pii            pair<int,int>
#define  ff             first
#define  ss             second
#define  vv             vector<int>
#define  all(v)         v.begin(),v.end()

#define MAX 1000001
vv prime;

void seive(){
   bool a[MAX];
   for(int i=0;i<MAX;++i) a[i]=true;
   for(int i=3; i*i<=MAX;i+=2){
    if(a[i]){
        for(int j=i*i;j<=MAX;j+=i)
            a[j]=false;
    }
   }
   prime.pb(2);
   for(int i=3;i<MAX;i+=2){
    if(a[i]) prime.pb(i);
   }
   //for(int i=0;i<100;i++) cout<<prime[i]<<" ";
   //for(auto x : prime) cout<<x<<" ";
}

void segSieve (ll l, ll r) {
    bool isPrime[r-l+1];
    for (int i = 0; i < r - l + 1; ++i) isPrime[i] = true;
    if (l == 1) isPrime[0] = false;
    for (int i = 0; prime[i]*prime[i] <= r; ++i) {
        int currentPrime = prime[i];
        ll base = (l/currentPrime)*currentPrime;
        if (base < l) base += currentPrime;
        for (ll j = base; j <= r; j += currentPrime) {
            isPrime[j-l] = false;
        }
        if (base == currentPrime) isPrime[base-l] = true;
    }
    for (int i = 0; i < r - l + 1; ++i) {
        if (isPrime[i]) cout << (i+l) << endl;
    }
    puts("");
}
int main()
{
    optimize
    seive();
    int q;
    cin>>q;
    while(q--){
        ll l,r;
        cin>>l>>r;
        segSieve(l,r);

    }
}
