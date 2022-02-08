#include<bits/stdc++.h>
using namespace std;
int main()
{
   long long n,r;
   cin>>n;
   double x=0;
   for(int i=1;i<=n;i++){
    x+=log10(i);
   }
   r=((int)x)+1;
   cout<<r<<endl;
}
