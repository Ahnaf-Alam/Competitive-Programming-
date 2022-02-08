#include<bits/stdc++.h>
using namespace std;
string lcs(string &X, string &Y)
{
    int m = X.length();
    int n = Y.length();

    int L[m+1][n+1];
    for (int i=0; i<=m; i++)
    {
        for (int j=0; j<=n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i-1] == Y[j-1])
                L[i][j] = L[i-1][j-1] + 1;
            else
                L[i][j] = max(L[i-1][j], L[i][j-1]);
        }
    }

    int index = L[m][n];
    string lcs(index+1, '\0');

    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (X[i-1] == Y[j-1])
        {
            // Put current character in result
            lcs[index-1] = X[i-1];
            i--;
            j--;

            // reduce values of i, j and index
            index--;
        }

        else if (L[i-1][j] > L[i][j-1])
            i--;
        else
            j--;
    }

    return lcs;
}
string longestPalSubseq(string &str)
{
     string rev = str;
    reverse(rev.begin(), rev.end());

    return lcs(str, rev);
}

int main()
{
    int t;
    cin>>t;
    while(t--){
      string s1;
    cin>>s1;
    string str=longestPalSubseq(s1);

    }

}
