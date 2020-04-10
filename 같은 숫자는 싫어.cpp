#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int cur=-1;
    for(auto num : arr)
    {
        if(cur!=num)
        {
            answer.push_back(num);
            cur=num;
        }
    }
    return answer;
}