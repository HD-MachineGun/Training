#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0, left = 0, right = int(people.size()) - 1;
    sort(people.begin(), people.end());
    while (left <= right)
    {
        if (people[left] + people[right] <= limit)
        {
            left++; right--; answer++;
        }
        else
        {
            right--; answer++;
        }
    }
    return answer;
}