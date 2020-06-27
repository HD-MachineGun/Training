#include <string>
#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;

// 0 우 1 하 2 좌 3 상
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int row,col;
struct user_pair
{
    int x,y,dir,cnt;
};

vector<string> map;
int draw_line[100][100];
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.

bool check_range(int x, int y)
{
    return 0<=x && x<row && 0<=y && y<col;
}

bool isClear(int sx, int sy, int tx, int ty)
{
    memset(draw_line,0,sizeof(draw_line));
    draw_line[sx][sy]=draw_line[tx][ty]=1;
    for(int i=0;i<4;i++)
    {
        int nx=sx,ny=sy;
        while(true)
        {
            nx+=dx[i]; ny+=dy[i];
            if(check_range(nx,ny) && (map[nx][ny]=='.' || map[nx][ny]==map[tx][ty]))
            {
                draw_line[nx][ny]++;
                if(draw_line[nx][ny]==2){ return true; }
            }
            else{ break; }
        }

        nx=tx,ny=ty;
        while(true)
        {
            nx+=dx[i]; ny+=dy[i]; 
            if(check_range(nx,ny) && (map[nx][ny]=='.' || map[nx][ny]==map[tx][ty]))
            {
                draw_line[nx][ny]++;
                if(draw_line[nx][ny]==2){ return true; }
            }
            else{ break; }
        }
    }
    return false;
}
    
string solution(int m, int n, vector<string> board) {
    string answer = "";
    row=m,col=n;
    // asize=정답 길이
    int asize=0;
    vector<vector<pair<int,int>>> alpa(26);
    map=board;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(map[i][j]!='.' && map[i][j]!='*')
            {
                alpa[map[i][j]-'A'].push_back(make_pair(i,j));
                asize++;
            }
        }
    }
    asize/=2;
    
    while(true)
    {
        bool check=true;
        for(int i=0;i<26;i++)
        {
            if(!alpa[i].empty())
            {
                int sx=alpa[i][0].first;
                int sy=alpa[i][0].second;
                int tx=alpa[i][1].first;
                int ty=alpa[i][1].second;
                
                // 지울수 있는지 확인
                if(isClear(sx,sy,tx,ty))
                {
                    check=false;
                    answer.push_back(char('A'+i));
                    map[sx][sy]=map[tx][ty]='.';
                    alpa[i].clear();
                    break;
                }
            }
        }
        // 모든 알파벳을 뒤져봄
        if(check){ break; }
    }
    cout<<answer<<endl;
    if(asize!=answer.size()){ answer="IMPOSSIBLE"; }
    
    return answer;
}