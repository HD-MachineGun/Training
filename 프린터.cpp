#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>> q;
    for (int i = 0; i < priorities.size(); i++)
    {
        q.push(make_pair(priorities[i], i));
    }
    sort(priorities.begin(), priorities.end(), greater<int>());

    while (!q.empty())
    {
        int prio = q.front().first;
        int loc = q.front().second;
        q.pop();

        if (prio != priorities.front())
        {
            q.push(make_pair(prio, loc));
            continue;
        }

        answer++;
        priorities.erase(priorities.begin());
        if (loc == location) { break; }
    }
    return answer;
}