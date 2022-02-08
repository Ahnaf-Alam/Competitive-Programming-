#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define  optimize   ios::sync_with_stdio(0); cin.tie(0);
#define PI  acos(-1.0)
#define RESET(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define pi pair<int,int>
#define ff first
#define ss second

int const mx = 200001;
int tmp[mx];
struct node{
   int sum,high;
}tree[3*mx];
int fwt[mx];
int p[mx]={0};
void init(int node,int b,int e){
  if(b==e){
    tree[node].sum=1;
    tree[node].high=tmp[b];
    return;
  }
  int left=node*2;
  int right=node*2+1;
  int mid=(b+e)/2;
  init(left,b,mid);
  init(right,mid+1,e);
  tree[node].sum = tree[left].sum+tree[right].sum;
  tree[node].high = max(tree[left].high,tree[right].high);
}
int query(int node,int b,int e,int i,int val){
    if(e<i) return tree[node].sum;
    if(b>i) return 0;
    if(b==i && e==i) return tree[node].sum;
    int left=node*2;
    int right = node*2 +1;
    int mid=(b+e)/2;
    int p1=query(left,b,mid,i,val);
    int p2=query(right,mid+1,e,i,val);
    return p1+p2;
}
void update(int node,int b,int e,int i,int val){
   if(i>e || i<b) return;
   if(b==e){
      tree[node].sum+=val;
      return;
   }
   int left=node*2;
   int right=node*2+1;
   int mid=(b+e)/2;
   update(left,b,mid,i,val);
   update(right,mid+1,e,i,val);
   tree[node].sum=tree[left].sum + tree[right].sum;
}

void update_fwt(int i,int x,int n){
   i++;
   while(i<=n){
     fwt[i]+=x;
     i+= ( i & -i);
   }
}

int main()
{
    optimize
    int n,x=0,val;
    cin>>n;
    for(int i=1;i<=n;i++) tmp[i]=x++;
    init(1,1,n);
    int ans;
    for(int i=1;i<=n;i++){
        cin>>val;
        ans=query(1,1,n,val+1,val);
        //cout<<ans-1<<" ";
        p[i-1]+=(ans-1);
        //cout<<p[i]<<" ";
        update(1,1,n,val+1,-1);
    }
    cout<<endl;
    RESET(tree,0);
    init(1,1,n);
    for(int i=1;i<=n;i++){
        cin>>val;
        ans=query(1,1,n,val+1,val);
        //cout<<ans-1<<" ";
        p[i-1]+=(ans-1);
        //cout<<p[i]<<" ";
        update(1,1,n,val+1,-1);
    }
    cout<<endl;
    for(int i=n-1;i>=0;i--)
    {
        int mod = n-i;
        if(p[i]>=mod)
        {
            p[i]-=mod ;
            if(i) p[i-1]++ ;
        }
    }
    //for(int i=1;i<=n;i++) cout<<p[i]<<" ";
    for(int i=0;i<n;i++) update_fwt(i,1,n);
    for(int i=0;i<n;i++){
        int sum=0;
        int pos=0;
        for(int j=32;j>=0;j--){
            if(pos+(1LL<<j)<n && sum+fwt[pos+(1LL<<j)]<p[i]+1){
                sum+=fwt[pos+(1LL<<j)];
                pos+=(1LL<<j);
            }
        }
        cout<<pos<<" ";
        update_fwt(pos,-1,n);
    }
}
