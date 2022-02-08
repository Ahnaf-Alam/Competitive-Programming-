#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define  prec(n)        fixed<<setprecision(n)
#define  optimize       ios::sync_with_stdio(0); cin.tie(0);
#define  PI             acos(-1.0)
#define  RESET(a, b)    memset(a, b, sizeof(a))
#define  pb             push_back
#define  pii            pair<int,int>
#define  ff             first
#define  ss             second

struct node{
   bool endmark;
   node *next[26+1];
   node()
   {
       endmark=false;
       for(int i=0;i<26;i++) next[i]=NULL;
   }
} *root;
void trie_insert(string& ch,int len){
    node* curr= root;
    for(int i=0;i<len;i++){
        int id= ch[i]-'a';
        if(curr->next[id]==NULL){
            curr->next[id]=new node();
        }
        curr = curr->next[id];
    }
    curr->endmark=true;
}
bool trie_search(string& ch,int len){
   node* curr= root;
   for(int i=0;i<len;i++){
     int id=ch[i]-'a';
     if(curr->next[id]==NULL) return false;
     curr = curr->next[id];
   }
   return curr->endmark;
}
void del(node* curr){
   for(int i=0;i<26;i++){
    if(curr->next[i]) del(curr->next[i]);
   }
   delete(curr);
}
int main()
{
    int n;
    root = new node();
    cin>>n;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        trie_insert(s,s.length());
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        string s;
        cin>>s;
        bool ans=trie_search(s,s.length());
        if(ans==1) cout<<"found"<<endl;
        else cout<<"not found"<<endl;
    }
    del(root);
    return 0;
}

