#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> budgets, int M) {
    int answer = 0;
    int Size=budgets.size();
    sort(budgets.begin(),budgets.end());
    int left=0, right=budgets[Size-1];
    while(left<=right)
    {
        int mid=(left+right)/2;
        int sum=0;
        
        for(int i=0;i<Size;i++)
        {
            if(mid<budgets[i]){ sum+=mid; }
            else{ sum+=budgets[i]; }
        }
        
        if(sum<=M)
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