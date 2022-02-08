#include<bits/stdc++.h>
using namespace std;
#define mx 100001
typedef long long ll;
int a[mx],tree[mx];

int query(int i){
   int sum=0;
   while(i>0){
    sum+=tree[i];
    i-= (i & -i);
   }
   return sum;
}
void update(int i,int x,int n){
   while(i<=n){
     tree[i]+=x;
     i+= ( i & -i);
   }
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        update(i,a[i],n);
    }
    //update(4,1,n);
    for(int i=0;i<n;i++) cout<<tree[i]<<" ";
    int ans=query(7);
    cout<<ans<<endl;
}
