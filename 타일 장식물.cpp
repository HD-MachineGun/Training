#include <string>
#include <vector>

using namespace std;

long long solution(int N) {
    long long answer[81];
    answer[1]=4;
    answer[2]=6;
    for(int i=3;i<=N;i++)
    {
        answer[i]=answer[i-1]+answer[i-2];
    }
    return answer[N];
}