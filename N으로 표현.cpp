#include <string>
#include <vector>

using namespace std;

const int MAX=987654321;
int ret=MAX;

void dp(int n,int target,int sum,int cnt)
{
    if(cnt>8 || ret<cnt){return;}
    if(target==sum)
    {
        ret=min(ret,cnt);
        return;
    }
    
    int next=0;
    for(int i=1;i+cnt<=8;i++)
    {
        next=next*10+n;
        dp(n,target,sum+next,cnt+i);
        dp(n,target,sum-next,cnt+i);
        dp(n,target,sum*next,cnt+i);
        dp(n,target,sum/next,cnt+i);
    }
}

int solution(int N, int number) {
    dp(N,number,0,0);
    return ret!=MAX ? ret:-1;
}