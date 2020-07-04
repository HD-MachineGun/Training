#include <string>
#include <vector>
using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    int num=s/n, rem=s%n;
    if(n>s){ answer.push_back(-1); }
    else
    {
        for(int i=0;i<n;i++)
        {
            if(i>=n-rem){ answer.push_back(num+1);}
            else{ answer.push_back(num); }
        }
    }
    return answer;
}