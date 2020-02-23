#include <string>
#include <vector>

using namespace std;

bool visited[201];

void dfs(int n, vector<vector<int>> computers,int here)
{
    visited[here]=true;
    for(int there=0;there<n;there++)
    {
        if(!visited[there] && computers[here][there])
        {
            dfs(n,computers,there);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            dfs(n,computers,i);
            answer++;
        }
    }
    return answer;
}