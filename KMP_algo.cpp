#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define  prec(n)        fixed<<setprecision(n)
#define  optimize       ios::sync_with_stdio(0); cin.tie(0);
#define  PI             acos(-1.0)
#define  RESET(a, b)    memset(a, b, sizeof(a))
#define  pb             push_back
#define  pii            pair<int,int>

// KMP Time complexity O(n+m) where n string length & m pattern length.
vector<int>LPS(string patt){
    vector<int>lps(patt.length());
    int indx=0;
    for(int i=1;i<patt.length();){
        if(patt[indx]==patt[i]){
            lps[i]=indx+1;
            i++;
            indx++;
        }
        else{
            if(indx!=0) indx=lps[indx-1];
            else lps[i]=indx, i++;
        }
    }
    return lps;
}
void KMP(string s,string patt){
    bool flag=false;
    vector<int> lps = LPS(patt);
    int i=0,j=0;
    // i for string and j for pattern
    int len=s.length();
    int plen=patt.length();
    while(i<len){
        if(s[i]==patt[j]) i++,j++;
        else{
            if(j!=0) j=lps[j-1];
            else ++i;
        }
        if(j == plen){
            cout<<"found\n";
            flag=true;
            cout<<"index : "<<i-patt.length()<<endl; // j index e paise pattern.
            j = lps[j-1];
        }
    }
    if(!flag) cout<<"NOT FOUND\n";
    for(auto x : lps) cout<<x<<" ";
    //for(int i=0;i<match.size();i++) cout<<match[i]<<" ";

}
int main()
{
    string s,patt;
    cin>>s>>patt;
    KMP(s,patt);
}
