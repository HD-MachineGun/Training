#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> weight) {
    sort(weight.begin(), weight.end());
    int answer = 1;

    for(auto w : weight)
    {
        if (answer >= w) 
        {
            answer += w;
        }
    }
    
    return answer;
}