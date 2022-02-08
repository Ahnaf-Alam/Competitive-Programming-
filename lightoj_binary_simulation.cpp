#include<bits/stdc++.h>
using namespace std;
#define mx 100001
typedef long long ll;
int a[mx];
int tree[3*mx];

void init(int node,int b,int e){
   if(b==e){
     tree[node]=0;
     return;
   }
   int left=node*2;
   int right=node*2+1;
   int mid=(b+e)/2;
   init(left,b,mid);
   init(right,mid+1,e);
   tree[node]=tree[left]+tree[right];
}
void update(int node,int b,int e,int i,int j){
    if(i>e || j<b) return;
    if(b >= i && e <= j){
        tree[node]++;
        return;
    }
    int left = node*2;
    int right = node*2+1;
    int mid = (b+e)/2;
    update(left,b,mid,i,j);
    update(right,mid+1,e,i,j);
    //return;
    //tree[node].sum=tree[left].sum+tree[right].sum+(e-b+1)*tree[node].prop;
}
int query(int node,int b,int e,int i,int j,int carry=0){
   if(i>e || j<b) return 0;
   if(b >= i && e <= j){
    return tree[node]+carry;
   }
    int left = node*2;
    int right = node*2+1;
    int mid = (b+e)/2;
    int p1=query(left,b,mid,i,j,carry+tree[node]);
    int p2=query(right,mid+1,e,i,j,carry+tree[node]);
    return max(p1,p2);
}
int main()
{
     int t,ca=0;
     cin>>t;
     while(t--){
        int q;
        char s[mx];
        scanf("%s",s);
        int n=strlen(s);
        init(1,0,n-1);
        scanf("%d",&q);
        printf("Case %d:\n",++ca);
        for(int i=0;i<q;i++){
            char c;
            int x,y;
            scanf(" %c",&c);
            //cin>>c;

            if(c=='I'){
                scanf("%d %d",&x,&y);
                update(1,0,n-1,--x,--y);
            }
            else{
                scanf("%d",&x);
                --x;
                int ans=query(1,0,n-1,x,x);
                //cout<<ans<<endl;
                if(ans%2==0) printf("%c\n",s[x]);
                else{
                    int tmp=s[x]-'0';
                    if(tmp==0) printf("1\n");
                    else printf("0\n");
                  //cout<<"invert"<<endl;
                }
            }
        }
     }
}
