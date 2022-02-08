#include<bits/stdc++.h>
using namespace std;
//Kadane's algo with indices ....O(n);
int strat,ed,s;
int MAXSUM(int a[],int n){
   int meh=0;
   int msf=INT_MIN;
   for(int i=0;i<n;i++){
    meh+=a[i];
    if(meh<a[i]){
        meh=a[i];
        s=i;
    }
    if(msf<meh){
        msf=meh;
        start=s;
        e=i;
    }
   }
   return msf;
}
int main()
{
    int n,ans;
    cin>>n;
    int a[n+2];
    for(int i=0;i<n;i++) cin>>a[i];
    ans=MAXSUM(a,n);
    cout<<ans<<endl;
}
