#include <string>
#include <vector>
#include <queue>
using namespace std;

// 오른쪽 0 아래 1 왼쪽 2 위 3
int xpos[4]={0,1,0,-1};
int ypos[4]={1,0,-1,0};

int nxpos[] = { -1,1,1,-1 };
int nypos[] = { 1,1,-1,-1 };

struct user_pair
{
    int x,y,dir,cnt;
};

bool visited[100][100][4];

bool check_range(int x, int y, int xx, int yy, int n)
{
    if (x < 0 || x >= n || y < 0 || y >= n) return false;
    if (xx < 0 || xx >= n || yy < 0 || yy >= n) return false;
    return true;
}

int solution(vector<vector<int>> board) {
    int Size=board.size();
    
    queue<user_pair> q;
    q.push({0,0,0,0});
    visited[0][0][0]=visited[0][1][2]=true;
    
    while(!q.empty())
    {
        int X=q.front().x;
        int Y=q.front().y;
        int Dir=q.front().dir;
        int Cnt=q.front().cnt;
        q.pop();
        
        int XX=X+xpos[Dir];
        int YY=Y+ypos[Dir];
        
        if(X==Size-1 && Y==Size-1){ return Cnt; }
        if(XX==Size-1 && YY==Size-1){ return Cnt; }
        
        // 방향 그대로 상하좌우 이동
        for(int i=0;i<4;i++)
        {
            int nx=X+xpos[i];
            int ny=Y+ypos[i];
            int nxx=XX+xpos[i];
            int nyy=YY+ypos[i];
            
            if (!check_range(nx, ny, nxx, nyy,Size)) continue;
            if (visited[nx][ny][Dir]) continue;
            if (board[nx][ny] == 1 || board[nxx][nyy] == 1) continue;
 
            visited[nx][ny][Dir] = true;
            q.push({nx, ny, Dir, Cnt + 1});
        }
        
        for (int i = 1; i < 4; i += 2) 
        {
            int nDir = (Dir + i) % 4;
            int nxx = X + xpos[nDir];
            int nyy = Y + ypos[nDir];
 
            int rx, ry;
            if (i == 1) 
            {
                //시계방향 회전
                rx = X + nxpos[nDir];
                ry = Y + nypos[nDir];
            }
            else 
            {
                //반시계방향 회전
                rx = X + nxpos[Dir];
                ry = Y + nypos[Dir];
            }
            
            if (!check_range(rx, ry, nxx, nyy,Size)) continue;
            if (visited[X][Y][nDir]) continue;
            if (board[nxx][nyy] == 1) continue;
            if (board[rx][ry]) continue;
 
            visited[X][Y][nDir] = true;
            q.push({X, Y, nDir, Cnt + 1});
        }
        
        // 다른 한점 90도 회전
        Dir = (Dir + 2) % 4; //xx, yy가 기준이므로 방향이 반대로 바뀐다.
        for (int i = 1; i < 4; i += 2) 
        {
            int nDir = (Dir + i) % 4;
            int nx = XX + xpos[nDir];
            int ny = YY + ypos[nDir];
 
            int rx, ry;
            if (i == 1) 
            {
                //시계방향 회전
                rx = XX + nxpos[nDir];
                ry = YY + nypos[nDir];
            }
            else 
            {
                //반시계방향 회전
                rx = XX + nxpos[Dir];
                ry = YY + nypos[Dir];
            }
 
            if (!check_range(nx, ny, rx, ry,Size)) continue;
            if (board[nx][ny] == 1) continue;
            if (board[rx][ry] == 1) continue;
 
            nDir = (nDir + 2) % 4;
            if (visited[nx][ny][nDir]) continue;
            visited[nx][ny][nDir] = true;
            q.push({nx, ny, nDir, Cnt + 1});
        }
    }
}