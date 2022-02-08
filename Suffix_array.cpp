#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
// find all suffix string in lexicographically sorted
// Time complexity O(nlog^2n)
// https://codeforces.com/edu/course/2/lesson/2/1

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

int main()
{
    string s;
    cin>>s;
    s+="$";
    int n=s.length();
    vv p(n),c(n);
    vector<pair<char,int>>a(n);
    for(int i=0;i<n;i++) a[i]={s[i],i};
    sort(all(a));

    for(int i=0;i<n;i++) p[i]=a[i].ss;
    c[p[0]]=0;
    for(int i=1;i<n;i++){
        if(a[i].ff==a[i-1].ff) c[p[i]]=c[p[i-1]];
        else c[p[i]]=c[p[i-1]]+1;
    }
    int k=0;
    while((1<<k)<n){
        vector<pair<pair<int,int>,int>>a(n);
        for(int i=0;i<n;i++){
            a[i]={{c[i],c[(i+(1<<k))%n]},i};
        }
        sort(all(a));
        for(int i=0;i<n;i++) p[i]=a[i].ss;
        c[p[0]]=0;
        for(int i=1;i<n;i++){
        if(a[i].ff==a[i-1].ff) c[p[i]]=c[p[i-1]];
        else c[p[i]]=c[p[i-1]]+1;
        }
        k++;
    }
    //for(int i=0;i<n;i++) cout<<p[i]<<" ";
    cout<<endl;
    for(int i=0;i<n;i++) cout<<p[i]<<" "<<s.substr(p[i],n-p[i])<<endl;
}
