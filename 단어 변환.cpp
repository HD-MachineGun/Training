#include <string>
#include <vector>

using namespace std;

bool visited[50];
int n,answer=987654321;

bool check(string a,string b)
{
    int ret=0;
    for(int i=0;i<a.length();i++)
    {
        if(a[i]!=b[i])
        {
            ret++;
        }
    }
    return ret==1;
}

void dfs(string target, vector<string> words, int index, int cnt)
{
    if(words[index]==target)
    {
        answer=min(answer,cnt);
    }
    
    for(int i=0;i<n;i++)
    {
        if(!visited[i] && check(words[index],words[i]))
        {
            visited[i]=true;
            dfs(target,words,i,cnt+1);
            visited[i]=false;
        }
    }
}
int solution(string begin, string target, vector<string> words) {
    n=words.size();
    for(int i=0;i<n;i++)
    {
        if(!visited[i] && check(begin,words[i]))
        {
            visited[i]=true;
            dfs(target,words,i,1);
            visited[i]=false;
        }
    }
    return answer==987654321 ? 0:answer;
}