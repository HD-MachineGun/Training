#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    int Size=times.size();
    sort(times.begin(),times.end());
    long long left=1;
    long long right=(long long)(times[Size-1])*n;
    long long answer = right;
    
    while(left<=right)
    {
        long long mid=(left+right)/2;
        long long cnt=0;
        for(int i=0;i<Size;i++)
        {
            cnt+=mid/(long long)times[i];
        }

        if(cnt<n){ left=mid+1; }
        else
        { 
            right=mid-1;
            answer=min(answer,mid);
        }
    }
    return answer;
}