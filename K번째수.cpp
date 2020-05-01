#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(int i=0;i<commands.size();i++)
    {
        int start=commands[i][0]-1;
        int finish=commands[i][1];
        int number=commands[i][2];
        vector<int> temp=array;
        sort(temp.begin()+start,temp.begin()+finish);
        answer.push_back(temp[start+number-1]);
    }
    return answer;
}