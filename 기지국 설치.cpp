#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer=0, start=0;
    vector<int> v;
    // ����x ���� ã��
    for(auto st: stations)
    {
        if(start>=st-w)
        {
            start=st+w;
            continue;
        }
        v.push_back(st-w-1-start);
        start=st+w;
    }
    if(start<n){ v.push_back(n-start); }
    // ������ ä���
    for(auto V: v)
    {
        int dis=2*w+1;
        int share=V/dis, remain=V%dis;
        answer+=share+(remain!=0 ? 1:0);
    }
    return answer;
}