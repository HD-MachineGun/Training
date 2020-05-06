#include <string>
#include <vector>

using namespace std;

vector<vector<int>> answer;

void add(int from, int to)
{
    vector<int> temp;
    temp.push_back(from);
    temp.push_back(to);
    answer.push_back(temp);
}

void Hanoi(int n, int from, int by, int to)
{
    if(n==1){ add(from,to); }
    else
    {
        Hanoi(n-1,from,to,by);
        add(from,to);
        Hanoi(n-1,by,from,to);
    }
}

vector<vector<int>> solution(int n) {
    Hanoi(n,1,2,3);
    return answer;
}