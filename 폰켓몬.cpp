#include <vector>
#include <string.h>
using namespace std;

int solution(vector<int> nums)
{
    int answer=0, nsize=nums.size();
    bool visited[200001];
    memset(visited,false,sizeof(visited));
    vector<int> result;
    for(auto num: nums)
    {
        if(visited[num]){ continue; }
        else
        { 
            visited[num]=true;
            result.push_back(num);
        }
    }
    
    if(nsize/2<result.size()){ answer=nsize/2; }
    else{ answer=result.size(); }
    
    return answer;
}