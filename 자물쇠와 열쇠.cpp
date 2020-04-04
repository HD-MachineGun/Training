#include <string>
#include <vector>
#include <queue>
using namespace std;

bool comp(vector<vector<int>> key, vector<vector<int>> map, int N)
{
    int M=key.size();
    int map_size=map.size();
    // 값 다 넣어주고 lock 부분이 모두 1인 것을 찾기
    for(int i=0;i<M+N-1;i++)
    {
        for(int j=0;j<M+N-1;j++)
        {
            vector<vector<int>> temp=map;
            for(int k=0;k<M;k++)
            {
                for(int t=0;t<M;t++)
                {
                    temp[i+k][j+t]+=key[k][t];
                }
            }
            
            bool check=false;
            for(int k=M-1;k<M+N-1;k++)
            {
                for(int t=M-1;t<M+N-1;t++)
                {
                    if(temp[k][t]!=1)
                    {
                        check=true;
                        break;
                    }
                }
                if(check){ break; }
            }
            if(!check){ return true;}
        }
    }
    return false;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    
    int M=key.size();
    int N=lock.size();
    
    // 하나의 큰 그림으로 key와 lock을 만듦
    int Size=M*2+N-2;
    
    vector<vector<int>> map(Size,vector<int>(Size,0));
    // map에 lock 부분 값 넣기
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            map[M-1+i][M-1+j]=lock[i][j];
        }
    }
    // 시계방향으로 4번 회전
    vector<vector<int>> temp(M,vector<int>(M));
    for(int cnt=0;cnt<4;cnt++)
    {
        for(int i=0;i<M;i++)
        {
            for(int j=0;j<M;j++)
            {
                temp[j][M-1-i]=key[i][j];
            }
        }
        if(comp(temp,map,N)){ return true; }
        key=temp;
    }
    return false;
}