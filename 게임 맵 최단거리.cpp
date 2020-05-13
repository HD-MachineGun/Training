#include<vector>
#include<queue>
using namespace std;

struct user_pair
{
    int x,y,cnt;
};

vector<vector<int>> map;
bool visited[100][100];

int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};

bool check_arrange(int x, int y, int n, int m)
{
    return 0<=x && x<n && 0<=y && y<m;
}

int BFS(int n, int m)
{
    queue<user_pair> q;
    q.push({0,0,1});
    visited[0][0]=true;
    
    while(!q.empty())
    {
        int x=q.front().x;
        int y=q.front().y;
        int cnt=q.front().cnt;
        q.pop();
        
        if(x==n-1 && y==m-1){ return cnt; }
        
        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i];
            int ny=y+dy[i];
            
            if(check_arrange(nx,ny,n,m) && map[nx][ny] && !visited[nx][ny])
            {
                q.push({nx,ny,cnt+1});
                visited[nx][ny]=true;
            }
        }
    }
    return -1;
}

int solution(vector<vector<int> > maps)
{
    int answer=0;
    map=maps;
    answer=BFS(maps.size(),maps[0].size());
    return answer;
}