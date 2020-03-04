#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int left=1, right=distance, MAX=-1;
    // 이분탐색은 정렬되어있어야 함
    sort(rocks.begin(),rocks.end());
    // 마지막 바위를 추가
    rocks.push_back(distance);
    
    // 바위사이의 거리가 mid이하일 경우 바위를 제거
    // 다 제거 후에 다리사이의 최솟값 찾기
    // 결론적으로 바위사이 거리의 마지노선을 이분탐색
    while(left<=right)
    {
        int cnt=0, prev=0, mid=(left+right)/2, MIN=1000000001;
        for(int i=0;i<rocks.size();i++)
        {
            if(rocks[i]-prev<=mid){ cnt++; }
            else
            {
                MIN=min(MIN,rocks[i]-prev);
                prev=rocks[i];
            }
        }
        // 제거한 바위갯수가 n보다 작은 조합이 여러개일 수 있음
        // 그 중 제일 큰 최솟값 찾기
        if(cnt<=n)
        { 
            MAX=max(MAX,MIN); 
            left=mid+1;
        }
        else{ right=mid-1; }
    }
    return MAX;
}