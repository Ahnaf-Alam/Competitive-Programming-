#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
// find all suffix string in lexicographically sorted using counting sort
// Time complexity O(nlogn)
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

void count_sort(vector<int> &p,vector<int> &c){
   int n=sz(p);
   vv cnt(n);
   for(auto x: c) cnt[x]++;
   vv p_new(n);
   vv pos(n);
   pos[0]=0;
   for(int i=1;i<n;i++){
    pos[i]=pos[i-1]+cnt[i-1];
   }
   for(auto x: p){
    int i=c[x];
    p_new[pos[i]]=x;
    pos[i]++;
   }
   p=p_new;
}
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
        for(int i=0;i<n;i++){
            p[i]=(p[i]-(1<<k)+n)%n;
        }
        count_sort(p,c);
        vv c_new(n);
        c_new[p[0]]=0;
        for(int i=1;i<n;i++){
            pii prev = {c[p[i-1]],c[(p[i-1]+(1<<k))%n]};
            pii now = {c[p[i]],c[(p[i]+(1<<k))%n]};
            if(prev==now){
                c_new[p[i]]=c_new[p[i-1]];
            }
            else{
                c_new[p[i]]=c_new[p[i-1]]+1;
            }
        }
        c=c_new;
        k++;
    }
    //for(int i=0;i<n;i++) cout<<p[i]<<" ";
    //for(int i=0;i<n;i++) cout<<p[i]<<" "<<s.substr(p[i],n-p[i])<<endl;
    vv lcp(n);
    int kk=0;
    for(int i=0;i<n-1;i++){
        int pi=c[i];
        int j=p[pi-1];
        // lcp[i]=lcp(s[i..],s[j...])
        while(s[i+kk]==s[j+kk]) kk++;
        lcp[pi]=kk;
        kk= max(kk-1,0);
    }
    for(int i=0;i<n;i++){
        cout<<lcp[i]<<" "<<p[i]<<" "<<s.substr(p[i],n-p[i])<<endl;
    }
}
