#include <vector>
#include <string.h>
using namespace std;

int MOD = 20170805;
int Right[501][501];
int Down[501][501];

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    memset(Right,0,sizeof(Right));
    memset(Down,0,sizeof(Down));
    
    Right[1][1]=Down[1][1]=1;
    
    for(int x=1;x<=m;x++)
    {
        for(int y=1;y<=n;y++)
        {
            if(city_map[x-1][y-1]==0)
            {
                Right[x][y]+=(Right[x][y-1]+Down[x-1][y])%MOD;
                Down[x][y]+=(Right[x][y-1]+Down[x-1][y])%MOD;
            }
            else if(city_map[x-1][y-1]==1)
            {
                Right[x][y]=Down[x][y]=0;
            }
            else
            {
                Right[x][y]=Right[x][y-1];
                Down[x][y]=Down[x-1][y];
            }
        }
    }
    
    return Right[m][n];
}