
#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
int r,c;
int fx[]={2,-2,2,-2,-1,-1,1,1};
int fy[]={-1,-1,1,1,2,-2,2,-2};
int level[1001][1001];
int vis[1001][1001];
void bfs(int x,int y){
   queue<pii>q;
   q.push(pii(x,y));
   vis[x][y]=1;
   while(q.size()>0){
      pii top=q.front();
      q.pop();
      for(int k=0;k<8;k++){
        int tx=top.first+fx[k];
        int ty=top.second+fy[k];
        //cout<<tx<<" "<<ty<<endl;
        if( tx>=1 && tx<=8 && ty>=1 && ty<=8 && vis[tx][ty]==0){
            level[tx][ty]=level[top.first][top.second]+1;
            vis[tx][ty]=1;
            q.push(pii(tx,ty));
        }
      }
   }
}
int main()
{
    char s1[10],s2[10];
    map<char,int>mp;
    mp['a'] = 1;
    mp['b'] = 2;
    mp['c'] = 3;
    mp['d'] = 4;
    mp['e'] = 5;
    mp['f'] = 6;
    mp['g'] = 7;
    mp['h'] = 8;
    while((scanf("%s %s",s1,s2))!=EOF){
         //cin>>s1>>s2;
         char c=s1[0];
         int x=mp[c];
         int y=s1[1]-'0';
         bfs(x,y);
         //cout<<x<<" "<<y<<endl;
         char c1=s2[0];
         int x1=mp[c1];
         int y1=s2[1]-'0';
         printf("To get from %c%d to %c%d takes %d knight moves.\n",c,y,c1,y1,level[x1][y1]-level[x][y]);
         //cout<<level[x1][y1]-level[x][y]<<endl;
         memset(level,0,sizeof(level));
         memset(vis,0,sizeof(vis));
    }
}
