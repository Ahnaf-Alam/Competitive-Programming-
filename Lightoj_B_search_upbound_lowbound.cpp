#include<bits/stdc++.h>
using namespace std;
int binarylower(int a[],int val,int n){
   int b=0,mid,index=-1;
   int e=n-1;
   while(b<=e){
    mid=(b+e)/2; //cout<<mid<<" ";
    //if(e==b) return mid;
    if(a[mid]==val){
        index=mid;
        e=mid-1;
    }
    if(a[mid]<val) b=mid+1;
    else if(a[mid]>val) e=mid-1;
   }
   return b;
}
int binaryupper(int a[],int val,int n){
   int b=0,mid,index=-1;
   int e=n-1;
   while(b<=e){
    mid=(b+e)/2; //cout<<mid<<" ";
    //if(e==b) return mid;
    if(a[mid]==val){
        index=mid;
        b=mid+1;
    }
    if(a[mid]<val) b=mid+1;
    else if(a[mid]>val) e=mid-1;
   }
   return e;
}
int main()
{
    int t,ca=0;
    cin>>t;
    while(t--){
        int n,q,x,y;
        scanf("%d %d",&n,&q);
        int a[n+2];
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        printf("Case %d:\n",++ca);
        for(int i=0;i<q;i++){
            scanf("%d%d",&x,&y);
            int r=binaryupper(a,y,n);
            int l=binarylower(a,x,n);
            //cout<<l<<" "<<r<<endl;
            printf("%d\n",r-l+1);
        }
    }
}
