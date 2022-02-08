#include<bits/stdc++.h>
using namespace std;

const int maxn = 1000005;
int K, ans[maxn], a[maxn], sum , m[maxn];

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
    if(m[a[index]]==1) sum++;

}
void remove(int index){
    m[a[index]]--;
    if(m[a[index]]==0) sum--;
}
int main()
{
     int n;
    scanf("%d",&n);

    K = sqrt(n);

    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    int q;
    scanf("%d",&q);

    for(int i=0;i<q;i++){
        scanf("%d %d",&query[i].L,&query[i].R);
        //cin >> query[i].L >> query[i].R;
        --query[i].L;
        --query[i].R;
        query[i].index = i;
    }
    sort(query,query+q);
    int L=0,R=-1;
    for(int i=0;i<q;i++){
        while(R<query[i].R){
            add(++R);
        }
        while(L<query[i].L) {
             remove(L++);
        }
        while(R>query[i].R) {
            remove(R--);
        }
        while(L>query[i].L) {
            add(--L);
        }
        ans[query[i].index]=sum;
    }
        for(int i=0;i<q;i++){
          printf("%d\n",ans[i]);
        //cout << ans[i] << "\n";
        }
}
