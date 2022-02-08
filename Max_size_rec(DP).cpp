
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define  prec(n)        fixed<<setprecision(n)
#define  optimize       ios::sync_with_stdio(0); cin.tie(0);
#define  PI             acos(-1.0)
#define  RESET(a, b)    memset(a, b, sizeof(a))
#define  pb             push_back
#define  pii            pair<int,int>
#define  pll            pair<ll,ll>
#define  vii            vector<int>
#define  vll            vector<ll>
#define  ff             first
#define  ss             second
#define  sz(v)          v.size()
#define  all(v)         v.begin(),v.end()

int const MOD=(int) 1e9+7;
inline void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD); }
inline ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline ll modAdd(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
inline ll modSub(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline ll modInverse(ll a) { return modPow(a, MOD-2); }
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }
inline ll mod(ll a, ll m){ if(a<0) return m-(abs(a)%m); else if(a<m) return a; else return (a%m); }
const int N = 3000006;
const int MAX=1000005;
// Time complexity is O(n*m)
// Space complexity is O(m)
int histogram(int a[],int n){
      int area=0,mx=0,curr=0,h,w;
      stack<int>s;
      s.push(-1);
      for(int i=0;i<n;i++){
        curr=a[i];
        while(s.top()!=-1 && curr<=a[s.top()]){
            int x=s.top();
            s.pop();
            h=a[x];
            w=i-s.top()-1;
            mx=h*w;
            area=max(mx,area);
        }
        s.push(i);
      }
       while(s.top()!=-1){
        int x=s.top();
        s.pop();
        h=a[x];
        w=n-s.top()-1;
        mx=h*w;
        area=max(area,mx);
      }
      return area;
}
int main()
{
    optimize
    int n,m;
    cin>>n>>m;
    int a[n+2][m+2];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin>>a[i][j];
    }
    int mxarea=0;
    int area=0;
    int tmp[m+2];
    RESET(tmp,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]==0) tmp[j]=0;
            else tmp[j]+=a[i][j];
        }

        area=histogram(tmp,m);
        mxarea=max(area,mxarea);
    }
    cout<<mxarea<<endl;
}
/*sample input
                         {{1,1,1,0},
                         {1,1,1,1},
                         {0,1,1,0},
                         {0,1,1,1},
                         {1,0,0,1},
                         {1,1,1,1}}

                         ans = 8*/

