#include<bits/stdc++.h>
using namespace std;
void LPSubstring(string &s){
    int n=s.size();
    if(n==0) return;
    n=n*2+1;
    int L[n];
    L[0] = 0;
    L[1] = 1;
    int C = 1,R=2,i=0;
    int iMirror;
    int maxLPSLength = 0;
    int maxLPSCenterPosition = 0;
    int start =-1,end=-1,diff=-1;
    for (i = 2; i < n; i++)
    {
        iMirror  = 2*C-i;
        L[i] = 0;
        diff = R - i;
        if(diff > 0)
            L[i] = min(L[iMirror], diff);

        while ( ((i + L[i]) < n && (i - L[i]) > 0) &&
            ( ((i + L[i] + 1) % 2 == 0) ||
            (s[(i + L[i] + 1)/2] == s[(i - L[i] - 1)/2] )))
        {
            L[i]++;
        }

        if(L[i] > maxLPSLength)  // Track maxLPSLength
        {
            maxLPSLength = L[i];
            maxLPSCenterPosition = i;
        }
        if (i + L[i] > R)
        {
            C = i;
            R = i + L[i];
        }
    }
    start = (maxLPSCenterPosition - maxLPSLength)/2;
    end = start + maxLPSLength - 1;
    //printf("LPS of string is %s : ", s);
    for(i=start; i<=end; i++)
        printf("%c", s[i]);
    printf("\n");
}
int main()
{
    string s;
    cin>>s;
    LPSubstring(s);
}
