#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    answer.push_back(0);
    for(int i=1;i<n;i++)
    {
        vector<int> temp=answer;
        temp.push_back(0);
        reverse(answer.begin(),answer.end());
        for(int j=0;j<answer.size();j++)
        {
            if(answer[j]==1){ temp.push_back(0); }
            else{ temp.push_back(1); }
        }
        answer=temp;
    }
    return answer;
}