#include<bits/stdc++.h>
using namespace std;
pair<int,int>p[10001];
int main()
{
    int n,m,j;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>p[i].first>>p[i].second;
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(j=0;j<=m;j++){
            if(i==0||j==0)
                dp[i][j]=0;
            else if(p[i-1].second<=j)
                dp[i][j]=max(p[i-1].first+dp[i-1][j-p[i-1].second],dp[i-1][j]);
            else dp[i][j]=dp[i-1][j];
        }
    }
    cout<<dp[n][m];
}
