#include <string>
#include <vector>

using namespace std;

int sum[2001];
// 부분합 이용
int solution(vector<int> cookie) {
    int answer=0, n=cookie.size();
    for(int i=0;i<n;i++)
    {
        sum[i+1]=sum[i]+cookie[i];
    }
    
    for(int i=1;i<n;i++)
    {
        int one=sum[i];
        for(int j=i+1;j<=n;j++)
        {
            int two=sum[j]-one;
            if(answer >= two || two > one){ continue; }
            for(int k=0;k<i;k++)
            {
                if(two==one-sum[k])
                {
                    answer=max(answer,two);
                    break;
                }
            }
        }
    }
    return answer;
}