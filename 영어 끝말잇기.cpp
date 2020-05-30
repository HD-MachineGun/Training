#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    vector<string> v;
    int index=1,cnt=1;
    char last=*(words[0].begin());
    for(int i=0;i<words.size();i++)
    {
        if(*(words[i].begin())!=last ||
          find(v.begin(),v.end(),words[i])!=v.end())
        {
            answer.push_back(index);
            answer.push_back(cnt);
            return answer;
        }
        v.push_back(words[i]);
        index++;
        if(index>n){ index=1; cnt++; }
        last=*(words[i].end()-1);
    }
    answer.push_back(0); answer.push_back(0);
    return answer;
}