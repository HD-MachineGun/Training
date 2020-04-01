#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {
    int end=prices.size()-1;
    vector<int> answer(end+1);
    stack<int> s;
    for(int i=0;i<end;i++)
    {
        while (!s.empty() && prices[s.top()] > prices[i]) 
        {
            int Top = s.top();
            s.pop();
            answer[Top] = i - Top;
        }
        s.push(i);
    }
    s.push(end);
    
    while(!s.empty())
    {
        int Top=s.top();
        s.pop();
        answer[Top]=end-Top;
    }
    return answer;
}