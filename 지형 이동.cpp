#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;

struct user_pair
{
    int x,y,cost;
};

int visited[300][300];
vector<vector<int>> map;
vector<int> parent(300,0);
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
const int MAX=987654321;
int N,HEIGHT,answer=MAX;

bool check_arrange(int x, int y)
{
    return 0<=x && x<N && 0<=y && y<N;
}

void dfs_division(int x, int y, int index)
{
    visited[x][y]=index;
    
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        
        if(check_arrange(nx,ny) && visited[nx][ny]==0 &&
          abs(map[nx][ny]-map[x][y]) <= HEIGHT)
        {
            dfs_division(nx,ny,index);
        }
    }
}

int Find(int x)
{
    if(parent[x]==x)
    {
        return parent[x];
    }
    else
    {
        return parent[x]=Find(parent[x]);
    }
}

bool isSame(int x, int y)
{
    int a=Find(x);
    int b=Find(y);
    
    if(a==b){ return true; }
    else{ return false; }
}

void Union(int x, int y)
{
    int a=Find(x);
    int b=Find(y);
    
    parent[b]=a;
}

bool comp(user_pair a, user_pair b)
{
    return a.cost<b.cost;
}
int solution(vector<vector<int>> land, int height) {
    int answer=0;
    map=land;
    N=land.size();
    HEIGHT=height;
    memset(visited,0,sizeof(visited));
    
    // 비용 없이 움직일 수 있는 구획 나누기
    int index=1;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(visited[i][j]==0)
            {
                dfs_division(i,j,index++);
            }
        }
    }
    // 인접노드 구하기
    vector<user_pair> edge;
    
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            for(int t=0;t<4;t++)
            {
                int nx=i+dx[t];
                int ny=j+dy[t];
                
                if(check_arrange(nx,ny) && visited[nx][ny]!=visited[i][j])
                {
                    int X=visited[i][j],Y=visited[nx][ny],cost=abs(map[nx][ny]-map[i][j]);
                    edge.push_back({X,Y,cost});
                }
            }
        }
    }
    
    // Kruskal 알고리즘 이용 각 구획을 연결하는 다리 놓기
    parent.resize(index+1);
    sort(edge.begin(),edge.end(),comp);
    for(int i=0;i<=index;i++){ parent[i]=i; }
    
    for(auto ed: edge)
    {
        int x=ed.x;
        int y=ed.y;
        int cost=ed.cost;
        
        if(!isSame(x,y))
        {
            Union(x,y);
            answer+=cost;
        }
    }
    return answer;
}