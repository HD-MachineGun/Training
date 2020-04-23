#include <string>
#include <vector>
#include <cstring>

using namespace std;

const int MAX=987654321;
int dp[201][201];
vector<vector<int>> m;
int msize;

int func(int start, int finish)
{
    if(start==finish){ return 0; }

    int& ret=dp[start][finish];
    if(ret!=-1){ return ret; }
    ret=MAX;
    for(int i=start;i<=finish;i++)
    {
        ret=min(ret,func(start,i)+func(i+1,finish)+m[start][0]*m[i][1]*m[finish][1]);
    }
    return ret;
}

int solution(vector<vector<int>> matrix_sizes) {
    int answer = 0;
    m=matrix_sizes;
    msize=m.size();
    memset(dp,-1,sizeof(dp));
    return func(0,msize-1);
}