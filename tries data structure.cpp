#include<bits/stdc++.h>
typedef long long ll;
ll M= 998244353;
using namespace std;
struct node{
  bool endmark;
  node* next[26+1];
  node(){
    endmark=false;
    for(int i=0;i<26;i++){
        next[i]=NULL;
    }
  }
} *root ;
void ins(char* str,int l){
  node* curnt=root;
  for(int i=0;i<l;i++){
    int tmp=str[i]-'a';
    if(curnt->next[tmp]==NULL){
        curnt->next[tmp]= new node();
    }
    curnt=curnt->next[tmp];
  }
    curnt->endmark=true;
}
bool srch(char* str,int l){
   node* curnt=root;
   for(int i=0;i<l;i++){
    int tmp=str[i]-'a';
    if(curnt->next[tmp]==NULL)
       return false;
     curnt=curnt->next[tmp];
   }
   return curnt->endmark;
}
void del(node* curnt){
    for(int i=0;i<26;i++){
        if(curnt->next[i])
            del(curnt);
    }
    delete (curnt);
}
int main()
{
     cout<<"Enter number of words: ";
     int n;
     cin>>n;
     root= new node();
     for(int i=1;i<=n;i++){
        char str[50];
        scanf("%s",str);
        ins(str,strlen(str));
     }
     int q;
     cin>>q;
     for(int i=0;i<q;i++){
        char s1[50];
        cin>>s1;
        if(srch(s1,strlen(s1)))
            cout<<"found"<<endl;
        else cout<<"Not found"<<endl;
     }
     del(root);
}
