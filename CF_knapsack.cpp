#include<bits/stdc++.h>
using namespace std;
int solve(string digit1,string digit2){
    int cnt=0;
    for(int i=0;i<7;i++){
        if(digit1[i]=='1' && digit2[i]=='0'){
            return -1;
        }
        cnt+=(digit1[i] != digit2[i]);
    }
    return cnt;
}
int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    int n,k,c=0;
    cin>>n>>k;
    vector<string> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<string> digit={ "1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
    int dp[n+2][k+1];
    memset(dp,-1,sizeof(dp));
    dp[n+1][0]=0;
    for(int i=n;i>=1;i--){
        for(int j=0;j<=k;j++){
            for(int d=9;d>=0;d--){
                c=solve(a[i],digit[d]);
                if(c==-1 || c>j) continue;
                if(dp[i+1][j-c]!=-1){
                    dp[i][j]=d;
                    break;
                }
            }
        }
    }
    if(dp[1][k]==-1) cout<<"-1\n";
    else{
        for(int i=1;i<=n;i++){
            cout<<dp[i][k];
            k-=solve(a[i],digit[dp[i][k]]);
        }
    }
}
