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
bool chk(int a,int b,int c,int g){
   if(a%g==0 && b%g==0 && c%g==0)
     return true;
   else return false;
}
int main()
{
    int a,b,x,y,c;
    cin>>a>>b>>c;
    int g=__gcd(a,b);
    if(chk(a,b,c,g)==false){
        cout<<"No solution exist"<<endl;
        return 0;
    }
    int A=a/g;
    int B=b/g;
    int C=c/g;
    if(g<0){
        a*=-1; b*=-1, c*=-1;
    }
    ext_gcd(A,B,&x,&y);
    x *=c, y *=c;
    cout<<x<<" "<<y<<endl;
    int k=1;
    cout<<"Another solution is "<<x+k*(b/g)<<" "<<y-k*(a/g)<<endl;
}
