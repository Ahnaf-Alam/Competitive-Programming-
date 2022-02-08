#include<bits/stdc++.h>
using namespace std;
int n,a[100001],dp[10001],dir[10001];
int longest(int u){
    if(dp[u]!=-1) return dp[u];
    int maxi=0;
    for(int v=u+1;v<=n;v++){
        if(a[v]>a[u]){
            if(longest(v)>maxi){
                maxi=longest(v);
                dir[u]=v;
            }
        }
    }
    dp[u]=1+maxi;
    return dp[u];
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    memset(dp,-1,sizeof(dp));
    memset(dir,-1,sizeof(dir));
    int lis=0,start;
    for(int i=1;i<=n;i++){
        if(longest(i)>lis){
            lis=longest(i);
            start=i;
        }
    }
    cout<<start<<" "<<lis<<endl;
    while(dir[start]!=-1){
        cout<<start<<" "<<a[start]<<endl;
        start=dir[start];
    }
}
