#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

int map[60001];

bool comp(vector<int> a, vector<int> b)
{
    return a[0]>b[0];
}
int solution(vector<vector<int>> routes) {
    int answer = 0;

    queue<pair<int,int>> q;
    sort(routes.begin(),routes.end(),comp);
    for(int i=0;i<routes.size();i++)
    {
        q.push(make_pair(routes[i][0],routes[i][1]));
    }
    
    while(!q.empty())
    {
        int MAX=q.front().first;
        q.pop();
        int qSize=q.size();
        answer++;
        
        for(int i=0;i<qSize;i++)
        {
            int start=q.front().first;
            int end=q.front().second;
            q.pop();

            if(!(start <= MAX && MAX <= end))
            {
                q.push(make_pair(start,end));
            }
        }
    }
    return answer;
}