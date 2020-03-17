#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

int parent[101];

bool comp(vector<int> a, vector<int> b)
{
    return a[2]<b[2];
}

int getParent(int a)
{
    if(parent[a]==a){ return a; }
    return getParent(parent[a]);
}

int unionParent(int a,int b)
{
    a=getParent(a);
    b=getParent(b);
    
    if(a<b)
    {
        parent[b]=a;
        return a;
    }
    else
    {
        parent[a]=b;
        return b;
    }
}

bool findParent(int a,int b)
{
    a=getParent(a);
    b=getParent(b);
    
    if(a==b){ return true; }
    else return false;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    sort(costs.begin(),costs.end(),comp);
    
    for(int i=0;i<n;i++){ parent[i]=i; }

    for(int i=0;i<costs.size();i++)
    {
        int x=costs[i][0];
        int y=costs[i][1];
        int cost=costs[i][2];
        
        if(!findParent(x,y))
        {
            answer+=cost;
            unionParent(x,y);
        }
    }
    return answer;
}