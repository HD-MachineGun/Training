#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct cmp 
{
    bool operator()(vector<int> a, vector<int> b) {
        return a[1] > b[1];
    }
};

int solution(vector<vector<int>> jobs) {
    int answer=0,index=0,time=0;
    sort(jobs.begin(),jobs.end());
    priority_queue<vector<int>,vector<vector<int>>,cmp> pq;
    while(index<jobs.size() || !pq.empty())
    {
        if(index<jobs.size() && time>=jobs[index][0])
        {
            pq.push(jobs[index++]);
            continue;
        }
        
        if (!pq.empty()) 
        {
            time += pq.top()[1];
            answer += time - pq.top()[0];
            pq.pop();
        }
        else{ time = jobs[index][0]; }
    }
    return answer/jobs.size();
}