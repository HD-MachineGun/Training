#include <string>
using namespace std;

bool visited[11][11][4];

bool check(int x, int y)
{
    return 0<=x && x<11 && 0<=y && y<11;
}

int solution(string dirs) {
    // 위 0 아래 1 왼쪽 2 오른쪽 3
	int answer = 0;
    int x=5,y=5;
    int num=1;
    for(auto com: dirs)
    {
        if(com=='U' && check(x-1,y))
        {
            if(!visited[x][y][0])
            {
                visited[x][y][0]=visited[x-1][y][1]=true;
                answer++;
            }
            x--;
        }
        else if(com=='D' && check(x+1,y))
        {
            if(!visited[x][y][1])
            {
                visited[x][y][1]=visited[x+1][y][0]=true;
                answer++;
            }
            x++;
        }
        else if(com=='L' && check(x,y-1))
        {
            if(!visited[x][y][2])
            {
                visited[x][y][2]=visited[x][y-1][3]=true;
                answer++;
            }
            y--;
        }
        else if(com=='R' && check(x,y+1))
        {
            if(!visited[x][y][3])
            {
                visited[x][y][3]=visited[x][y+1][2]=true;
                answer++;
            }
            y++;
        }
    }
	return answer;
}