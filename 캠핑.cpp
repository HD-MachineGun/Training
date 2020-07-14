#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

bool isZero(vector<int> a, vector<int> b)
{
    return a[0] != b[0] && a[1] != b[1];
}

int solution(int n, vector<vector<int>> data) {
    int answer = 0, dsize = data.size();
    sort(data.begin(), data.end());

    for (int i = 0; i < dsize; i++)
    {
        for (int j = i + 1; j < dsize; j++)
        {
            if (!isZero(data[i], data[j])) { continue; }
            int minX = min(data[i][0], data[j][0]), maxX = max(data[i][0], data[j][0]);
            int minY = min(data[i][1], data[j][1]), maxY = max(data[i][1], data[j][1]);

            bool flag = true;
            for (int k = i + 1; k <= j; k++)
            {
                if (minX < data[k][0] && minY < data[k][1] &&
                    data[k][0] < maxX && data[k][1] < maxY)
                {
                    flag = false;
                    break;
                }
            }
            if (flag) { answer++; }
        }
    }
    return answer;
}