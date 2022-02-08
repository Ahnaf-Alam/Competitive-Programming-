#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
typedef long long ll;
using    namespace __gnu_pbds;

#define  prec(n)        fixed<<setprecision(n)
#define  optimize       ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define  PI             acos(-1.0)
#define  RESET(a, b)    memset(a, b, sizeof(a))
#define  pb             push_back
#define  sz(v)          v.size()
#define  pii            pair<int,int>
#define  pll            pair<ll,ll>
#define  ff             first
#define  ss             second
#define  vv             vector<int>
#define  all(v)         v.begin(),v.end()
#define  Yes            cout<<"Yes\n"
#define  No             cout<<"No\n"

const ll MOD= 998244353;
inline void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD); }
inline ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline ll modAdd(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
inline ll modSub(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline ll modInverse(ll a) { return modPow(a, MOD-2); }inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }
inline ll mod(ll a, ll m){ if(a<0) return m-(abs(a)%m); else if(a<m) return a; else return (a%m); }

const int MAX = 1e6+5;
const int N = 2e5+4;
const ll INF = 1e18;
const int LN =  20;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

struct node{
    int pa,open,close;
    node(){
       pa=open=close=0;
    }
}Tree[3*MAX];
int n;
string s;
void init(int NODE,int b,int e){
   //cout<<"yes"<<endl;
   if(b==e){
       Tree[NODE].pa=0;
       if(s[b-1]=='(') Tree[NODE].open=1;
       else Tree[NODE].close=1;
       return;
   }
   int mid=(b+e)/2;
   int le=2*NODE;
   int ri = 2*NODE+1;
   init(le,b,mid);
   init(ri,mid+1,e);
   int mn = min(Tree[le].open,Tree[ri].close);
   Tree[NODE].pa = Tree[le].pa + Tree[ri].pa + mn;
   Tree[NODE].open = Tree[le].open+Tree[ri].open-mn;
   Tree[NODE].close = Tree[le].close+Tree[ri].close-mn;
   return;
}
node query(int NODE,int b,int e,int idx){
    if(b>idx || e<idx){
        node tmp;
        tmp.pa= Tree[NODE].pa;
        tmp.open=Tree[NODE].open;
        tmp.close = Tree[NODE].close;
        return tmp;
    }
    if(b==e && b==idx){
        node tmp;
        tmp.pa=Tree[NODE].pa;
        if(s[idx-1]=='('){
            tmp.open=0;
            tmp.close=1;
        }
        else{
            tmp.open=1;
            tmp.close=0;
        }
        return tmp;
    }
    int mid=(b+e)/2;
    int left=2*NODE;
    int right =2*NODE+1;
    node p1 = query(left,b,mid,idx);
    node p2 = query(right,mid+1,e,idx);
    int mn = min(p1.open,p2.close);
    node parent;
    parent.pa = p1.pa+p2.pa+mn;
    parent.open = p1.open+p2.open-mn;
    parent.close = p1.close+p2.close-mn;
    //cout<<parent.pa<<" "<<parent.open<<" "<<parent.cl
    return parent;

}
void update(int NODE,int b,int e,int idx){
     if(b>idx || e<idx) return;
     if(b==e && b==idx){
         if(s[idx-1]=='('){
             s[idx-1]=')';
             Tree[NODE].open=0;
             Tree[NODE].close=1;
         }
         else if(s[idx-1]==')'){
            s[idx-1]='(';
            Tree[NODE].open=1;
            Tree[NODE].close=0;
         }
         return;
     }
     int mid=(b+e)/2;
     int left = 2*NODE;
     int right = 2*NODE+1;
     update(left,b,mid,idx);
     update(right,mid+1,e,idx);
     int mn = min(Tree[left].open,Tree[right].close);
     Tree[NODE].pa = Tree[left].pa + Tree[right].pa + mn;
     Tree[NODE].open = Tree[left].open+Tree[right].open-mn;
     Tree[NODE].close = Tree[left].close+Tree[right].close-mn;
     return;
}
void solve(){
    cin>>n>>s;
    RESET(Tree,0);
    init(1,1,n);
    int q; cin>>q;
    while(q--){
        int id; cin>>id;
        if(id==0){
            if(Tree[1].open==0 && Tree[1].close==0) cout<<"YES\n";
            else cout<<"NO\n";
        }
        else update(1,1,n,id);
    }
}
int main()
{
     optimize
     int t=1,ca=0; //cin>>t;
     while(t--){
        solve();
     }
}
// problem:
//https://codeforces.com/contest/1095/problem/E
//https://www.spoj.com/problems/BRCKTS/
