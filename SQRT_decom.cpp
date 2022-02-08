#include<bits/stdc++.h>
using namespace std;
typedef  long long int ll;

#define  prec(n)        fixed<<setprecision(n)
#define  optimize       ios::sync_with_stdio(0); cin.tie(0);
#define  PI             acos(-1.0)
#define  RESET(a, b)    memset(a, b, sizeof(a))
#define  pb             push_back
#define  sz(v)          v.size()
#define  pii            pair<int,int>
#define  ff             first
#define  ss             second
#define  vv             vector<int>
#define  all(v)         v.begin(),v.end()

int seg[20001];
int block;
void init(int a[],int n){
   int cur=-1;
    block=sqrt(n);
   for(int i=0;i<n;i++){
     if(i%block==0){
        cur++;
     }
     seg[cur]+=a[i];
   }
}
int query(int a[],int l,int r){
    int sum=0;
    while(l<r && l%block !=0){
        sum+=a[l];
        l++;
    }
    while(l+block<=r){
        sum+=seg[l/block];
        l+=block;
    }
    while(l<=r){
        sum+=a[l];
        l++;
    }
    return sum;
}
void update(int a[],int i,int val){
     int seg_no=i/block;
     seg[seg_no]-=a[i];
     seg[seg_no]+=val;
     a[i]=val;
}
int main()
{
    int n;
    cin>>n;
    int a[n+2];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    init(a,n);
    cout<<query(a,1,5)<<endl;
    update(a,1,4);
    cout<<query(a,1,5)<<endl;
}
