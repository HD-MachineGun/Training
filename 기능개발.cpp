#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int day=0;
    vector<int> time;
    for(int i=0;i<speeds.size();i++)
    {
        // ¸ò+³ª¸ÓÁö
        int base=progresses[i], s=speeds[i];
        time.push_back((100-base)/s+((100-base)%s==0 ? 0 : 1));
    }

    int temp=time[0], cnt=0, idx=0;
    for(int i=0;i<time.size();i++)
    {
        if(temp>=time[i]){ cnt++; }
        else
        {
            answer.push_back(cnt);
            temp=time[i]; cnt=1;
        }
    }
    if(cnt>0){ answer.push_back(cnt); }
    return answer;
}