#include<bits/stdc++.h>
using namespace std;

const int maxn = 200002;
int K, ans[maxn], a[maxn], sum;
map<int,int> m;
struct Query{
    int index, L, R;
    bool operator < (const Query &other) const {
		int block_own = L/K;
		int block_other = other.L/K;
		if(block_own == block_other)
            return R < other.R;
		return block_own < block_other;
	}
}query[maxn];

void add(int index){
    m[a[index]]++;
    sum=max(sum,m[a[index]]);
}

void remove(int index){
    m[a[index]]--;
    sum=min(sum,m[a[index]]);
}

int main(){
    while(1){
    int n,q;
    scanf("%d",&n);
    if(n==0) break;
    scanf("%d",&q);

    K = sqrt(n);

    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    for(int i=0;i<q;i++){
        cin >> query[i].L >> query[i].R;
        --query[i].L;
        --query[i].R;
        query[i].index = i;
    }
    sort(query, query+q);
    int L=0, R=-1;
    for(int i=0;i<q;i++){
        while(R<query[i].R) add(++R);
        while(L<query[i].L) remove(L++);
        while(R>query[i].R) remove(R--);
        while(L>query[i].L) add(--L);
        ans[query[i].index] = sum;
    }
    for(int i=0;i<q;i++){
        cout << ans[i] << "\n";
    }
     return 0;
    }
}
