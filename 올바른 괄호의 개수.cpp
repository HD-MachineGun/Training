#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n) {
    int answer = 0;
    vector<char> v;
    for (int i = 0; i < n * 2; i++)
    {
        if (i % 2 == 0) { v.push_back('('); }
        else { v.push_back(')'); }
    }

    sort(v.begin(), v.end());
    do
    {
        int cnt = 0;
        bool check = true;
        for (auto bracket : v)
        {
            if (bracket == '(') { cnt++; }
            else { cnt--; }
            if (cnt < 0) { check = false; break; }
        }
        if (check) { answer++; }
    } while (next_permutation(v.begin(), v.end()));
    return answer;
}