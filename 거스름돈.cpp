#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

const long long MAX=1000000007;
int solution(int n, vector<int> money) {
    sort(money.begin(),money.end());
    long long dp[100001];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<=n;i+=money[0]){ dp[i]=1; }
    for(int i=1;i<money.size();i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(dp[j]>0 && j+money[i]<=n)
            {
                dp[j+money[i]]+=dp[j]%MAX;
            }
        }
    }
    return dp[n];
}