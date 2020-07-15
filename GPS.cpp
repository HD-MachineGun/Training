#include <vector>
using namespace std;

const int MAX = 987654321;
int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
    int answer = MAX;
    vector<vector<int>> gps_dp(101, vector<int>(201, MAX));
    vector<vector<int>> adj(n + 1);
    for (auto ed : edge_list)
    {
        adj[ed[0]].push_back(ed[1]);
        adj[ed[1]].push_back(ed[0]);
    }

    gps_dp[0][gps_log[0]] = 0;
    // i번째 log를 j로 바꿀시 필요한 modify count
    for (int i = 1; i < k; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int modi = 0;
            if (gps_log[i] != j) { modi = 1; }
            // j에 있었는데 또 j에 있는경우
            gps_dp[i][j] = min(gps_dp[i][j], gps_dp[i - 1][j] + modi);
            // 연결된 자리가 j인 경우
            for (auto k : adj[j])
            {
                gps_dp[i][j] = min(gps_dp[i][j], gps_dp[i - 1][k] + modi);
            }
        }
    }

    for (auto i : adj[gps_log.back()])
    {
        answer = min(answer, gps_dp[k - 2][i]);
    }
    return answer == MAX ? -1 : answer;
}