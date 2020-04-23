#include <string>
#include <vector>
#include <math.h>
using namespace std;

vector<int> solution(long long begin, long long end) {
    vector<int> answer;
    for(long long i=begin;i<=end;i++)
    {
        if(i==1){ answer.push_back(0); continue; }
        bool check=true;
        for(long long j=2;j<=sqrt(i);j++)
        {
            if(i%j==0 && i/j<=10000000)
            { 
                answer.push_back(i/j); 
                check=false;
                break;
            }
        }
        if(check){ answer.push_back(1); }
    }
    return answer;
}