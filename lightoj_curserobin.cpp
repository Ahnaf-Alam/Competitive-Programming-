#include<bits/stdc++.h>
using namespace std;
#define mx 100001
typedef long long ll;
int a[mx],tree[mx];

ll query(int i){
   ll sum=0;
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
    int t,ca=0;
    cin>>t;
    while(t--){
    int n,q;
    //cin>>n;
    memset(tree,0,sizeof(tree));
    sizeof(a,0,sizeof(a));
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        update(i,a[i],n);
    }
    printf("Case %d:\n",++ca);
    for(int i=1;i<=q;i++){
        int typ,l,r;
        scanf("%d",&typ);
        if(typ==1){
            scanf("%d",&l);
            ++l;
            update(l,-a[l],n);
            printf("%d\n",a[l]);
            a[l]=0;
            //cout<<tree[l]<<endl;
        }
        else if(typ==2){
            scanf("%d %d",&l,&r);
            update(++l,r,n);
            a[l]+=r;
            //cout<<tree[l]<<endl;
        }
        else{
            scanf("%d%d",&l,&r);
            ++l;
            ++r;
            ll ans1=query(r);
            ll ans2=query(l-1);
            printf("%lld\n",ans1-ans2);
        }
    }
    }
}

