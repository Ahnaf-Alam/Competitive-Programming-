#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100001];
struct X{
  ll sum,md;
}tree[3*100001];

void init(int node,int b,int e){
   if(b==e){
     tree[node].sum=a[b];
     tree[node].md=a[b];
     return;
   }
   int left=node*2;
   int right=node*2+1;
   int mid=(b+e)/2;
   init(left,b,mid);
   init(right,mid+1,e);
   tree[node].sum=tree[left].sum+tree[right].sum;
   tree[node].md=max(tree[left].md,tree[right].md);
}
void func(int node,int b,int e,int i,int j,int mod){
    if(i>e || j<b || tree[node].md<mod) return;
    if(b==e){
        tree[node].md%=mod;
        tree[node].sum%=mod;
        return;
    }
     int left=node*2;
   int right=node*2+1;
   int mid=(b+e)/2;
    func(left,b,mid,i,j,mod);
    func(right,mid+1,e,i,j,mod);
    tree[node].sum=tree[left].sum+tree[right].sum;
   tree[node].md=max(tree[left].md,tree[right].md);
}
ll query(int node,int b,int e,int i,int j){
   if(i>e || j<b) return 0;
   if(b>=i && e<=j) return tree[node].sum;
   int left=node*2;
   int right=node*2+1;
   int mid=(b+e)/2;
   ll p1=query(left,b,mid,i,j);
   ll p2=query(right,mid+1,e,i,j);
   return p1+p2;
}
void update(int node,int b,int e,int i,int val){
   if(i>e || i<b) return;
   if(b==e){
     tree[node].sum=tree[node].md=val;
     return;
   }
   int left=node*2;
   int right=node*2+1;
   int mid=(b+e)/2;
   update(left,b,mid,i,val);
   update(right,mid+1,e,i,val);
   tree[node].sum=tree[left].sum+tree[right].sum;
   tree[node].md=max(tree[left].md,tree[right].md);
}
int main()
{
    int n,m,typ;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    init(1,1,n);
    for(int i=0;i<m;i++){
        cin>>typ;
        if(typ==3){
            int l,x;
            cin>>l>>x;
            update(1,1,n,l,x);
        }
        else if(typ==2) {
            int l,r,mod;
            cin>>l>>r>>mod;
                func(1,1,n,l,r,mod);
        }
        else{
            int l,r;
            cin>>l>>r;
            //for(int j=1;j<=7;j++) cout<<tree[j].sum<<" ";
            ll ans=query(1,1,n,l,r);
            cout<<ans<<endl;
        }
    }
}
