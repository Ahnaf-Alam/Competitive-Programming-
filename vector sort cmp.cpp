#include<bits/stdc++.h>
#define ll long long
using namespace std;
stack<ll>s;
vector<int>v;
ll a[1000001];
bool cmp(int i,int j){
    return (a[i]<a[j]);
}
int main()
{
    ll n; string r;
    scanf("%lld",&n);
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
        v.push_back(i);
    }
    cin>>r;
    sort(v.begin(),v.end(),cmp);
    //for(int i=0;i<v.size();i++)
      //  cout<<v[i]<<" ";
    int k=0;
    for(int i=0;i<2*n;i++){
        if(r[i]=='0'){
            s.push(v[k]+1);
            cout<<s.top()<<" ";
            k++;
        }
        else if(r[i]=='1'){
            cout<<s.top()<<" ";
            s.pop();
        }
    }
    return 0;
}
