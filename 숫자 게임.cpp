#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(A.begin(),A.end(),greater<int>());
    sort(B.begin(),B.end(),greater<int>());
    int a=0,b=0,asize=A.size();
    while(a<asize)
    {
        if(A[a]<B[b]){ a++; b++; answer++; }
        else{ a++; }
    }
    return answer;
}