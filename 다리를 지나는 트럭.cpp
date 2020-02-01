#include <iostream>
#include <string>
#include <vector>
using namespace std;

void minusil(vector<pair<int, int>>& v)
{
    for (int i = 0; i < int(v.size()); i++)
    {
        v[i].second--;
    }
}

void erasezero(vector<pair<int, int>>& v)
{
    for (int i = 0; i<int(v.size()); i++)
    {
        if (v[i].second == 0) { v.erase(v.begin() + i); }
    }
}

int sumweight(vector<pair<int, int>> v)
{
    int sum = 0;
    for (int i = 0; i < int(v.size()); i++)
    {
        sum += v[i].first;
    }
    return sum;
}

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int time = 0, sum = 0;

    vector<int>::iterator iter = truck_weights.begin();
    vector<pair<int, int>> wait;

    while (iter != truck_weights.end())
    {
        time++;
        erasezero(wait);

        int temp = sumweight(wait);

        if (temp + (*iter) <= weight)
        {
            wait.push_back({ *iter,bridge_length });
            iter++;
        }
        
        minusil(wait);
    }
    
    while (!wait.empty()) 
    {
        
        time++;
        erasezero(wait);
        minusil(wait); 
    }

    return time;
}

int main()
{
    vector<int> v = {10,10,10,10,10,10,10,10,10,10};
    cout << solution(100,100 ,v);
}
