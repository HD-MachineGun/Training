#include <string>
#include <vector>
#include <string.h>

using namespace std;

vector<vector<int>> temp;
int cache[100001][101];

int dp(int K,int tsize,int n,int time)
{
    if(n>tsize-1){return 0;}

    int& ret=cache[time][n];
    if(ret!=-1){return ret;}
    
    int uptime=temp[n][0],bottime=temp[n][2];
    int upmoney=temp[n][1],botmoney=temp[n][3];
    
    int upsum=-1,botsum=-1;
    
    if(time+uptime<=K){ upsum=upmoney+dp(K,tsize,n+1,time+uptime); }
    if(time+bottime<=K){ botsum=botmoney+dp(K,tsize,n+1,time+bottime); }
    
    return ret=max(upsum,botsum);
}

int solution(int K, vector<vector<int>> travel) {
    int tsize=travel.size();
    temp=travel;
    memset(cache,-1,sizeof(cache));
    return dp(K,tsize,0,0);
}