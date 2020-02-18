#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

bool dfs(string here, vector<int>& visited, vector<vector<string>> tickets, vector<string>& answer)
{
	answer.push_back(here);
    for(vector<vector<string>>::iterator it=tickets.begin();it!=tickets.end();it++)
    {
        int idx = it-tickets.begin();
        if(visited[idx] == false && (*it)[0] == (*(answer.end()-1)))
        {
            visited[idx]=true;
            bool check=dfs((*it)[1],visited,tickets,answer);
            if(check){ return true; }
            else{ visited[idx]=false; }
        }
    }
    
    if(int(tickets.size())==int(answer.size())-1){ return true; }
    answer.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    vector<int> visited(tickets.size());
	sort(tickets.begin(), tickets.end());
	dfs("ICN", visited, tickets, answer);
	return answer;
}
