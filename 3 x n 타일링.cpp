#include <string>
#include <vector>
#include <string.h>
using namespace std;

long long cache[5001];

long long func(int num)
{
    long long& ret=cache[num];
    if(ret!=0){ return ret; }
    
    ret+=3*func(num-2);
    for(int i=4;i<=num;i+=2)
    {
        ret+=2*func(num-i);
    }
    ret%=1000000007;
    return ret;
}
int solution(int n) {
    memset(cache,0,sizeof(cache));
    cache[0]=1; cache[2]=3;
    int answer=func(n);
    return answer;
}