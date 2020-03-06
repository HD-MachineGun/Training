#include <string>
#include <vector>
#include <string.h>
#include <iostream>
using namespace std;

int N;
vector<vector<bool>> graph;

vector<vector<bool>> make_graph(int n, vector<vector<int>> results)
{
    vector<vector<bool>> temp(n+1,vector<bool>(n+1,false));
    for(int i=0;i<results.size();i++)
    {
        int x=results[i][0];
        int y=results[i][1];
        temp[x][y]=true;
    }
    return temp;
}

void floyd_warshall()
{
    int cnt=1;
    for(int k=1;k<=N;k++)
    {
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=N;j++)
            {
                // i=j �̰ų� i�� j�� cnt�ΰ�� 
                if(i==j || i==k || j==k){ continue; }

                // �׳� ���� vs cnt�� ������ ���İ��� ���
                if(graph[i][k] && graph[k][j])
                {
                    graph[i][j]=true;
                }
            }
        }
    }
}

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    N=n;
    graph=make_graph(n, results);
    floyd_warshall();
    for(int i=1;i<=N;i++)
    {
        int count=0;
        for(int j=1;j<=N;j++)
        {
            if(graph[i][j] || graph[j][i]){ count++; }
        }
        if(count==n-1){ answer++; }
    }
    return answer;
}