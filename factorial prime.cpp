#include<bits/stdc++.h>
using namespace std;
vector<int>prime;
vector<int>factor;
int a[100001];
int pf[100001];
void seive(int n)
{
      for(int i=0;i<100001;i++)
        a[i]=0;
    a[0]=a[1]=1; prime.push_back(2);
    for(int i=4;i<=n;i=i+2)
        a[i]=1;
    for(int i=3;i<=sqrt(n);i=i+2){
        if(a[i]==0){
            for(int j=i*i;j<=n;j+=2*i)
                a[j]=1;
        }
    }
    for(int i=3;i<=n;i=i+2)
        if(a[i]==0) prime.push_back(i);
}
void fact(int x)
{
    for(int i=0;i<prime.size()&&prime[i]<=sqrt(x);i++){
        if(x%prime[i]==0){
            while(x%prime[i]==0){
                x=x/prime[i];
                factor.push_back(prime[i]);
                pf[prime[i]]++;
            }
        }
    }
    if(x!=1){
        factor.push_back(x);
        pf[x]++;
    }
}
int main()
{
    int t;
    cin>>t;
    for(int j=1;j<=t;j++){
     int n;
     memset(a,0,sizeof(a));
     memset(pf,0,sizeof(pf));
      scanf("%d",&n);
     seive(n);
     for(int i=2;i<=n;i++)
      fact(i);
     cout<<"Case "<<j<<": "<<n<<" = ";
     for(int i=0;i<prime.size();i++){
       cout<<prime[i]<<" "<<"("<<pf[prime[i]]<<")";
       if(i!=prime.size()-1) printf(" * ");
     }
    cout<<endl;
    prime.clear();
    factor.clear();
    }
}
