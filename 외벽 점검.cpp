#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool visited[8];
int answer=-1,dist_size;

vector<vector<int>> weak_list;
vector<int> DIST;

void dfs(vector<int> result, int cnt)
{
    if(cnt==0)
    {
        for(int i=0;i<weak_list.size();i++)
        {
            bool check=true;
            vector<int>::iterator it=result.begin();
            int temp=weak_list[i][0]+*(it++);

            for(int j=0;j<weak_list[i].size();j++)
            {
                if(weak_list[i][j]<=temp){ continue; }
                // 커버할 수 없는 거리면 다음 사람에게 맡긴다.
                if(it!=result.end())
                {
                    temp=weak_list[i][j]+*(it++);
                }
                else
                {
                    check=false;
                    break;
                }
            }

            if(check)
            { 
                answer=result.size(); 
                return; 
            }
        }
    }
    
    for(int i=0;i<DIST.size();i++)
    {
        if(!visited[i])
        {
            visited[i]=true;
            result.push_back(DIST[i]);
            
            dfs(result,cnt-1);
            if(answer!=-1){ return; }
            
            visited[i]=false;
            result.pop_back();
        }
    }
}

int solution(int n, vector<int> weak, vector<int> dist) {
    DIST=dist;
    weak_list.push_back(weak);
    for(int i=0;i<weak.size()-1;i++)
    {
        int temp=weak[0]+n;
        weak.erase(weak.begin());
        weak.push_back(temp);
        weak_list.push_back(weak);
    }
    vector<int> result;
    for(int i=1;i<=dist.size();i++)
    {
        dfs(result,i);
        if(answer!=-1){ return answer; }
    }
    return answer;
}