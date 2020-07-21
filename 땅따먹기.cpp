#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    int dp[100001][4];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < 4; i++) { dp[0][i] = land[0][i]; }
    for (int floor = 1; floor < land.size(); floor++)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (i != j)
                {
                    dp[floor][i] = max(dp[floor][i], land[floor][i] + dp[floor - 1][j]);
                }
            }
        }
    }
    for (auto a : dp[land.size() - 1]) { answer = max(answer, a); }
    return answer;
}