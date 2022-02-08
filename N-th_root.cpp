#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define  prec(n)        fixed<<setprecision(n)
#define  optimize       ios::sync_with_stdio(0); cin.tie(0);
#define  PI             acos(-1.0)
#define  RESET(a, b)    memset(a, b, sizeof(a))
#define  pb             push_back
#define  pii            pair<int,int>

double nthroot(double n,int k){
   double x=(1.0/k)*(log(n)/log(k));
   return pow(k,x);
}
int main()
{
    double n;
    int k;
    cin>>n>>k;
    cout<<nthroot(n,k);
}

