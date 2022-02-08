#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> z(100001);
void z_algo(string s){
   int len=s.length();
   int l,r;
   l=r=0;
   for(int i=1;l<len;i++){
    if(i>r){
        l=r=i;
        while(r<len && s[r]==s[r-l])
            r++;
        z[i]=r-l;
        r--;
    }
    else{
        int idx=i-l;
        if(z[idx]<r-i+1){
            z[i]=z[idx];
        }
        else{
            l=i;
            while(r<len && s[r]==s[r-l])
                r++;
            z[i]=r-l;
            r--;
        }
    }
   }
}
int main()
{
    string s,pat,tot;
    cin>>s>>pat;
    tot=s;
    z_algo(tot);
    for(int i=0;i<tot.size();i++){
        //cout<<z[i]<<" ";
        if(z[i]==pat.length()){
            cout<<i-pat.length()-1<<endl;
        }
    }
}
