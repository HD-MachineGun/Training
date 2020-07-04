#include <iostream>
#include <string>
using namespace std;
int solution(string s)
{
    int answer=0,ssize=s.length();
    for(int i=0;i<ssize;i++)
    {
        int left,right,temp;
        left=i-1,right=i+1,temp=1;
        
        while(0<=left && right<ssize)
        {
            if(s[left]!=s[right]){ break; }
            else
            {
                temp+=2;
            }
            left--; right++;
        }
        answer=max(answer,temp);
        
        left=i-1,right=i,temp=0;
         while(0<=left && right<ssize)
        {
            if(s[left]!=s[right]){ break; }
            else
            {
                temp+=2;
            }
            left--; right++;
        }
        answer=max(answer,temp);
    }
    return answer;
}