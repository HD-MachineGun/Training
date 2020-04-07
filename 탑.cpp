#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    stack<int> s;
    while(!heights.empty())
    {
        int top=heights.back();
        heights.pop_back();
        while(heights.back()<=top)
        {
            s.push(heights.back());
            heights.pop_back();
        }
        if(heights.size()==-1){ answer.push_back(0); }
        else{ answer.push_back(heights.size()); }
        while(!s.empty())
        {
            heights.push_back(s.top());
            s.pop();
        }
    }
    reverse(answer.begin(),answer.end());
    return answer;
}