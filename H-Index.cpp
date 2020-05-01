#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    int answer=0;
    int csize=citations.size();
    sort(citations.begin(),citations.end(),greater<int>());
    citations.insert(citations.begin(),-1);
    for(int i=1;i<=csize;i++)
    {
        if(citations[i]>=i)
        {
           answer=i;
        }
    }
    return answer;
}