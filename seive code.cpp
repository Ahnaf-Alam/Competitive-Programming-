#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>prime;
    int n,h,a[100001];
    scanf("%d",&n);
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
    cout<<prime.size()<<endl;
    /*for(int i=0;i<prime.size();i++)
        cout<<prime[i]<<" ";*/
}
