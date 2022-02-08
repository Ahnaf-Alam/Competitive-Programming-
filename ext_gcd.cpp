#include<bits/stdc++.h>
using namespace std;
int ext_gcd(int A,int B,int *X,int *Y){
   int x2,x1,y1,y2,x,y,r2,r1,q,r;
   x1=0,y1=1,x2=1,y2=0;
   r2=A,r1=B;
   while(r1){
    q=r2/r1;
    r=r2%r1;
    x=x2-(q*x1);
    y=y2-(q*y1);
    r2=r1;
    r1=r;
    x2=x1;
    x1=x;
    y2=y1;
    y1=y;
   }
   *X=x2,*Y=y2;
   return r2;
}
int main()
{
    int a,b,x,y;
    cin>>a>>b;
    cout<<ext_gcd(a,b,&x,&y)<<endl;
    cout<<x<<" "<<y<<endl;
}
