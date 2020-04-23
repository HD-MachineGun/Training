#include <string>
#include <vector>
#include <string.h>

using namespace std;

int cache[1000000][2],n;
vector<int> a;

int dp(int idx,bool ch)
{
    if(idx>=n){return 0;}
    
    int& ret=cache[idx][ch];
    if(ret!=-1){return ret;}
    
    //첫번째 집을 털 경우
    if(idx==0)
    {
        ret=a[idx]+max(ret,dp(idx+2,true));
    }
    //마지막 집을 털 경우 ch=false일때만 텀
    else if(idx==n-1)
    {
        if(!ch)
        {
            ret=a[idx]+max(ret,dp(idx+2,ch));
        }
    }
    else
    {
        ret=a[idx]+max(ret,dp(idx+2,ch));
    }
    ret=max(ret,dp(idx+1,ch));

    return ret;
}

int solution(vector<int> money) {
    a=money;
    n=money.size();
    memset(cache,-1,sizeof(cache));
    return dp(0,false);
}