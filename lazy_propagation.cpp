#include<bits/stdc++.h>
using namespace std;
#define mx 100001
typedef long long ll;
int a[mx];
struct info{
    ll prop,sum;
}tree[mx*3];

void init(int node,int b,int e){
   if(b==e){
     tree[node].sum=a[b];
     return;
   }
   int left=node*2;
   int right=node*2+1;
   int mid=(b+e)/2;
   init(left,b,mid);
   init(right,mid+1,e);
   tree[node].sum=tree[left].sum+tree[right].sum;
}
void update(int node,int b,int e,int i,int j,ll newval){
    if(i>e || j<b) return;
    if(i<=b && j<=e){
        tree[node].sum+=(e-b+1)*newval;
        tree[node].prop+=newval;
        return;
    }
    int left = node*2;
    int right = node*2+1;
    int mid = (b+e)/2;
    update(left,b,mid,i,j,newval);
    update(right,mid+1,e,i,j,newval);
    tree[node].sum=tree[left].sum+tree[right].sum+(e-b+1)*tree[node].prop;
}
int query(int node,int b,int e,int i,int j,int carry=0){
   if(i>e || j<e) return 0;
   if(b>=i && e<=j){
    return tree[node].sum+carry*(e-b+1);
   }
    int left = node*2;
    int right = node*2+1;
    int mid = (b+e)/2;
    int p1=query(left,b,mid,i,j,carry+tree[node].prop);
    int p2=query(left,mid+1,e,i,j,carry+tree[node].prop);
    return p1+p2;
}
int main()
{
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++) cin>>a[i];
    init(1,1,n);
    update(1,1,n,1,n,2);
}
