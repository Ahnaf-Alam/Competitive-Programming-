#include<bits/stdc++.h>
using namespace std;
int coin[]={5,8,11,15,18}; //value of coins available
int make; //our target value
int dp[6][100];
int call(int i,int amount)
{
    if(i>=5) { //All coins have been taken
        if(amount==make)return 1;
        else return 0;
    }
    if(dp[i][amount]!=-1) return dp[i][amount]; //no need to calculate same state twice
    int ret1=0,ret2=0;
    if(amount+coin[i]<=make) ret1=call(i,amount+coin[i]); //try to take coin i
    ret2=call(i+1,amount); //dont take coin i
    return dp[i][amount]=ret1|ret2; //storing and returning.

}
int main()
{
    // freopen("in","r",stdin);
    while(cin>>make)
    {
        memset(dp,-1,sizeof(dp));
        cout<<call(0,0)<<endl;
    }
    return 0;
}

