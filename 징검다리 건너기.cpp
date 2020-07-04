#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> stones, int k) {
    int answer=0;
    int maxnum=*max_element(stones.begin(),stones.end());
    int minnum=*min_element(stones.begin(),stones.end());
    int left=minnum,right=maxnum;
    
    while(left<=right)
    {
        int mid=(left+right)/2;
        int cnt=0;
        bool check=true;
        for(auto s:stones)
        {
            if(mid>s)
            {
                cnt++;
                if(cnt>=k)
                {
                    check=false;
                    break;
                }
            }
            else{ cnt=0; }
        }
        
        if(check)
        {
            answer=max(answer,mid);
            left=mid+1;
        }
        else
        {
            right=mid-1;
        }
    }

    return answer;
}