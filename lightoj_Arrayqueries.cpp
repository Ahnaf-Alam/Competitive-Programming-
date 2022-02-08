#include<bits/stdc++.h>
using namespace std;
#define mx 100001;
int tree[3*100001];
int a[100001],n;
void init(int node,int b,int e){
   if(b==e){
     tree[node]=a[b];
     return;
   }
   int left=node*2;
   int right=node*2+1;
   int mid=(b+e)/2;
   init(left,b,mid);
   init(right,mid+1,e);
   tree[node]=tree[left]+tree[right];
}
int query(int node,int b,int e,int i,int j){
     if(i>e || j<b) return 0;
     if(b>=i && e<=j){
        return tree[node];
     }
     int left=node*2;
     int right=node*2+1;
     int mid=(b+e)/2;
     int p1=query(left,b,mid,i,j);
     int p2=query(right,mid+1,e,i,j);
     return p1+p2;
}
void update(int node,int b,int e,int i,int newval){
     if(i>e || i<b) return;
     if(b>=i && i<=e){
        tree[node]+=newval;
        return;
     }
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    update(left,b,mid,i,newval);
    update(right,mid+1,e,i,newval);
    tree[node]=tree[left]+tree[right];
}

int main()
{
    int t,ca=0;
    scanf("%d",&t);
    while(t--){
      int q;
      memset(tree,0,sizeof(tree));
      scanf("%d%d",&n,&q);
      for(int i=0;i<n;i++)  scanf("%d",&a[i]);
      printf("Case %d:\n",++ca);
      init(1,0,n-1);
      for(int i=0;i<q;i++){
        int tt,l,r;
        scanf("%d",&tt);
        if(tt==1){
            scanf("%d",&l);
            printf("%d\n",a[l]);
            //a[l]=0;
            //init(1,1,n);
            update(1,0,n-1,l,-a[l]);
            a[l]=0;
        }
        else if(tt==2){
            scanf("%d%d",&l,&r);
            //cout<<r<<endl;
            update(1,0,n-1,l,r);
            a[l]=a[l]+r;
        }
        else if(tt==3){
            scanf("%d%d",&l,&r);
            int ans=query(1,0,n-1,l,r);
            printf("%d\n",ans);
        }
      }
    }

}

