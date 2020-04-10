#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct user_pair
{
    int x,y,type;
    unsigned operator ==(user_pair temp)
    {
        return (x==temp.x && y==temp.y && type==temp.type );
    }
};

int N;

bool check(vector<user_pair> map)
{
    for(vector<user_pair>::iterator it=map.begin();it!=map.end();it++)
    {
        int x=(*it).x;
        int y=(*it).y;
        int type=(*it).type;
        if(type)
        {// ��
            // ���� �� �κ��� ��� ���� �ְų�, �Ǵ� ���� �� �κ��� �ٸ� ����
            // ���ÿ� ����Ǿ� �־�� �մϴ�.
            user_pair k1={x,y-1,0}, k2={x+1,y-1,0}, k3={x-1,y,1}, k4={x+1,y,1};
            if( find(map.begin(),map.end(),k1)!=map.end() ||
               find(map.begin(),map.end(),k2)!=map.end() ||
               (find(map.begin(),map.end(),k3)!=map.end() &&
               find(map.begin(),map.end(),k4)!=map.end()) ){ continue; }
            else return false;
        }
        else
        {// ���
            // �ٴ� ���� �ְų� ���� ���� �� �κ� ���� �ְų�, �Ǵ�
            // �ٸ� ��� ���� �־�� �մϴ�.
            user_pair k1={x-1,y,1}, k2={x,y,1}, k3={x,y-1,0};
            if( y==0 || find(map.begin(),map.end(),k1)!=map.end() ||
               find(map.begin(),map.end(),k2)!=map.end() ||
               find(map.begin(),map.end(),k3)!=map.end() ){ continue; }
            else return false;
        }
    }
    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    N=n;
    vector<user_pair> map;
    for(auto com : build_frame)
    {
        int x=com[0];
        int y=com[1];
        int type=com[2];
        int exec=com[3];
        if(exec)
        {// ��ġ
            map.push_back({x,y,type});
            if(!check(map))
            {
                map.pop_back();
            }
        }
        else
        {// ����
            user_pair k1={x,y,type};
            vector<user_pair>::iterator tempit=find(map.begin(),map.end(),k1);
            map.erase(tempit);
            
            if(!check(map))
            {
                map.push_back({x,y,type});
            }
        }
    }
    for(int i=0;i<map.size();i++)
    {
        vector<int> temp;
        temp.push_back(map[i].x);
        temp.push_back(map[i].y);
        temp.push_back(map[i].type);
        answer.push_back(temp);
    }
    sort(answer.begin(),answer.end());
    return answer;
}