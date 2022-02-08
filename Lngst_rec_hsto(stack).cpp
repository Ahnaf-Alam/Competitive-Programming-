#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t,ca=0;
    cin>>t;
    while(t--){
    ll area=0,mx=0;
    int n,a[30001],h,w;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    stack<int>s;
    int curr=0;
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
    printf("Case %d: %lld\n",++ca,area);
    }
}
