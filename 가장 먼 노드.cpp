#include <string>
#include <vector>
#include <queue>
 
using namespace std;
 
int solution(int n, vector<vector<int>> edge) {
    int answer=0;
    
    bool adj[20001][20001];
    bool check[20001];
    
    for(int i=0;i<int(edge.size());i++)
    {
        int a=edge[i][0];
        int b=edge[i][1];
        adj[a][b]=adj[b][a]=true;
    }
    
    queue<int> q;
    q.push(1);
    check[1]=true;
    
    while(!q.empty())
    {
        answer=q.size();
        
        for(int i=0;i<answer;i++)
        {
            int here=q.front();
            q.pop();
            
            for(int there=1;there<=n;there++)
            {
                if(!check[there] && adj[here][there])
                {
                    check[there]=true;
                    q.push(there);
                }
            }
        }
    }
    
    return answer;
}