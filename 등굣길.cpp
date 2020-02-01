#include <string>
#include <vector>
#include <string.h>
using namespace std;

int cache[101][101];
bool map[101][101];

int path(int a, int b, int m, int n)
{
    if (a == m && b == n) { return 1; }
    if (a > m || b > n || map[a][b]) { return 0; }

    int& ret = cache[a][b];
    if (ret != -1) { return ret; }
    ret = (path(a + 1, b, m, n) + path(a, b + 1, m, n)) % 1000000007;

    return ret;
}

int solution(int m, int n, vector<vector<int>> puddles)
{
    for (int i = 0; i < puddles.size(); i++)
    {
        map[puddles[i][0]][puddles[i][1]] = true;
    }
    memset(cache, -1, sizeof(cache));
    return path(1, 1, m, n);
}