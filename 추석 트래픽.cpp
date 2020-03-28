#include <string>
#include <vector>
using namespace std;

// 24시간=86400*1000마이크로초

int map[86400001];
string make_T(string s)
{
    if(s.size()==1)
    {
        s.push_back('.');
    }
    if(s.size()<5){
        while(s.size() != 5)
        {
            s.push_back('0');
        }
    }
    return s;
}

int read_T(string s)
{
    s.erase(s.begin()+1);
    return stoi(s);
}

int solution(vector<string> lines) {
    int answer = 0;
    for(int i=0;i<lines.size();i++)
    {
        int h=stoi(lines[i].substr(11,2))*60*60*1000;
        int m=stoi(lines[i].substr(14,2))*60*1000;
        int s=stoi(lines[i].substr(17,2))*1000;
        int ss=stoi(lines[i].substr(20,3));
        int end=h+m+s+ss+999;
        
        lines[i].pop_back();
        string s_T=make_T(lines[i].substr(24));
        int T=read_T(s_T);
            
        int begin=end-T+1-999;
        
        if(begin<0){ begin=0; }
        if(end>86400000){ end=86400000; }
        
        for(int j=begin;j<=end;j++)
        {
            map[j]++;
        }
    }

    for(int i=0;i<=86400000;i++)
    {
        answer=max(answer,map[i]);
    }
    return answer;
}