#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer=0, bsize=board.size();
    int map[30][30];
    
    for(int i=0;i<bsize;i++)
    {
        for(int j=0;j<bsize;j++)
        {
            map[i][j]=board[i][j];
        }
    }
    
    stack<int> s;
    for(auto m: moves)
    {
        m--;
        int idx=0;
        while(map[idx][m]==0 && idx<bsize){  idx++; }
        // idx�� bsize�� ����� continue
        if(idx>=bsize){ continue; }

        int pet=map[idx][m];
        map[idx][m]=0;
        // top�� �ٸ��� push ������ ���ֱ�
        if(s.empty() || s.top()!=pet)
        { 
            s.push(pet);
        }
        else
        { 
            s.pop();
            answer++; 
        }
    }
    return answer*2;
}