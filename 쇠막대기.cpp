#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(string arrangement) {
    int answer=0,time=0;
    stack<int> s;
    vector<pair<int,int>> lazer;
    vector<pair<int,int>> namu;
    for(auto a: arrangement)
    {
        if(a=='(')
        {
            s.push(time++);
        }
        else
        {
            if((time-s.top())==1)
            {
                lazer.push_back(make_pair(time-1,time));
                s.pop();
            }
            else
            {
                namu.push_back(make_pair(s.top(),time));
                s.pop();
            }
            time++;
        }
    }
    
    for(auto n: namu)
    {
        int sum=0;
        for(auto l: lazer)
        {
            if(l.second < n.first){ continue; }
            if(l.second < n.second){ sum++; }
            else{ break; }
        }
        answer+=sum+1;
    }
    return answer;
}