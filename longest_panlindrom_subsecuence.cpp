#include<bits/stdc++.h>
using namespace std;
string s,str;
int dp[1001][1001];
int Palindrome(string &s,int n){
    for(int i=0;i<n;i++)
        dp[i][i]=1;
    for(int l=2;l<=n;l++){
        for(int i=0;i<n-l+1;i++){
            int j=i+l-1;
            if(l==2 && s[i] == s[j]) dp[i][j]=2;
            else if(s[i] == s[j]) dp[i][j]=dp[i+1][j-1]+2;
            else dp[i][j]=max(dp[i+1][j],dp[i][j-1]);

        }
    }
    return dp[0][n-1];
}
void Trace(int i,int j){
   if(i==j){
      str+=s[j];
      return;
   }
   if(dp[i][j]==0) return;
   if(dp[i][j-1]==dp[i+1][j]){
      str+=s[i];
      Trace(i+1,j-1);
   }
   else{
       int x=max(dp[i][j-1],dp[i+1][j]);
       if(x==dp[i][j-1]) Trace(i,j-1);
       else Trace(i+1,j);
   }
}
int main()
{
    cin>>s;
    int len=s.length();
    int ans=Palindrome(s,len);
    cout<<ans<<endl;
}
