#include <string>
#include <vector>
#include <string.h>
#include <iostream>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer=0,num=1;
    int alpa[26];
    memset(alpa,0,sizeof(alpa));
    
    for(auto s: skill)
    {
        int index=s-'A';
        alpa[index]=num++;
    }
    
    for(auto sk: skill_trees)
    {
        int cur=0;
        bool check=true;
        for(auto s: sk)
        {
            int index=s-'A';
            if(alpa[index]==0){ continue; }
            else
            {
                if(cur+1!=alpa[index])
                {
                    check=false;
                    break;
                }
                else{ cur++; }
            }
        }
        if(check){ answer++; }
    }
    
    return answer;
}