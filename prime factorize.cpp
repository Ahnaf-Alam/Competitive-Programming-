#include<bits/stdc++.h>
using namespace std;
vector<int>prime;
vector<int>factor;
int a[1000001];
const int MAX=1000000;
void seive()
{
      for(int i=0;i<MAX;i++)
        a[i]=0;
    a[0]=a[1]=1; prime.push_back(2);
    for(int i=4;i<=MAX;i=i+2)
        a[i]=1;
    for(int i=3;i<=sqrt(MAX);i=i+2){
        if(a[i]==0){
            for(int j=i*i;j<=MAX;j+=2*i)
                a[j]=1;
        }
    }
    for(int i=3;i<=MAX;i=i+2)
        if(a[i]==0) prime.push_back(i);
}
void fact(int x)
{
    for(int i=0;i<prime.size()&&prime[i]<=sqrt(x);i++){
        if(x%prime[i]==0){
            while(x%prime[i]==0){
                x=x/prime[i];
                factor.push_back(prime[i]);
            }
        }
    }
    if(x!=1)
        factor.push_back(x);
}
int main()
{
    int n;
    scanf("%d",&n);
    seive();
    fact(n);
    for(int i=0;i<factor.size();i++)
        cout<<factor[i]<<" ";
}
