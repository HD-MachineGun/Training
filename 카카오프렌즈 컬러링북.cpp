#include <vector>
#include <string.h>
using namespace std;

bool visited[100][100];
vector<vector<int>> map;

int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
int M,N;

bool check_arrange(int x, int y)
{
    return 0<=x && x<M && 0<=y && y<N;
}

int DFS(int x, int y, int color)
{
    visited[x][y]=true;
    int sum=0;
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        
        if(check_arrange(nx,ny) && !visited[nx][ny] && map[nx][ny]==color)
        {
            sum+=1+DFS(nx,ny,color);
        }
    }
    return sum;
}
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    memset(visited,false,sizeof(visited));
    map=picture; M=m; N=n;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(map[i][j]==0 || visited[i][j]){ continue; }
            max_size_of_one_area=max(max_size_of_one_area,1+DFS(i,j,map[i][j]));
            number_of_area++;
        }
    }
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}