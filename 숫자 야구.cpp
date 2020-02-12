#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> baseball) {
    int answer=0;
    for(int i=123;i<=987;i++)
    {
        string target=to_string(i);
        //0 이거나 같거나
        if(target[0]=='0' || target[1]=='0' || target[2]=='0'){continue;}
        if(target[0]==target[1] || target[1]==target[2] || target[0]==target[2]){continue;}
        bool check=true;
        for(int j=0;j<int(baseball.size());j++)
        {
            string num=to_string(baseball[j][0]);
            int strike=0,ball=0;
            //strike
            for(int k=0;k<3;k++)
            {
                if(target[k]==num[k]){strike++;}
            }
            //ball
            for(int k=0;k<3;k++)
            {
                for(int t=0;t<3;t++)
                {
                    if(k==t){continue;}
                    if(num[k]==target[t]){ball++;}
                }
            }
            if(strike!=baseball[j][1] || ball!=baseball[j][2]){check=false; break;}
        }
        if(check){answer++;}
    }
    return answer;
}