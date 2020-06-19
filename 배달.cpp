#include <vector>
#include <string.h>
using namespace std;

const int MAX=987654321;
bool visit[51];
int c[51];
int cost[51][51];

int getSmallNum(int N)
{
    int num=MAX,ret=-1;
    for(int i=1;i<=N; i++)
    {
        if(c[i] < num && !visit[i])
        {
            num=c[i];
            ret=i;
        }
    }
    return ret;
}

void dijkstra(int N, int start)
{
    for(int i=1;i<=N;i++)
    {
        c[i]=cost[start][i];
    }
    
    visit[start]=true;
    while(true)
    {
        int current=getSmallNum(N);
        if(current==-1){ break; }
        visit[current]=true;
        for(int i=1;i<=N;i++)
        {
            if(!visit[i] && c[i] > c[current]+cost[current][i])
            {
                c[i]=c[current]+cost[current][i];
            }
        }
    }
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;

    for(int i=0;i<=50;i++)
    {
        for(int j=0;j<=50;j++)
        {
            if(i==j){ cost[i][j]=0; }
            else{ cost[i][j]=MAX; }
        }
    }
    
    for(int i=0;i<road.size();i++)
    {
        int x=road[i][0];
        int y=road[i][1];
        int c=min(cost[x][y],min(cost[y][x],road[i][2]));
        cost[x][y]=cost[y][x]=c;
    }
    
    dijkstra(N,1);
    
    for(int i=1;i<=N;i++)
    {
        if(c[i] <= K){ answer++; }
    }
    
    return answer;
}