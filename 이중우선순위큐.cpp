#include <string>
#include <vector>
#include <sstream>
#include <queue>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int> pq;
    for(auto oper: operations)
    {
        stringstream ss;
        ss.str(oper);
        string op,num;
        ss>>op>>num;
        
        if(op=="I"){ pq.push(stoi(num)); }
        else
        {
            if(pq.empty()){ continue; }
            
            if(num=="1"){ pq.pop(); }
            else
            {
                priority_queue<int> temp;
                while(!pq.empty())
                {
                    if(pq.size()==1){ break; }
                    temp.push(pq.top());
                    pq.pop();
                }
                pq=temp;
            }
        }
    }
    if(pq.empty())
    { 
        answer.push_back(0); 
        answer.push_back(0); 
    }
    else
    {
        answer.push_back(pq.top());
        while(pq.size()!=1){ pq.pop(); }
        answer.push_back(pq.top());
    }
    return answer;
}