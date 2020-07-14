#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

// k���� ����°� �ƴ϶� length-k���� �����ϴ� ������ �ٲ�
string solution(string number, int k) {
    string answer = "";
    int cnt = number.size() - k;
    int left = 0, right = number.size() - cnt;

    while (cnt > 0)
    {
        int maxnum = -1, idx = 0;

        for (int i = left; i <= right; i++)
        {
            int temp = number[i] - '0';
            if (maxnum < temp)
            {
                maxnum = temp;
                idx = i;
            }
        }
        answer += to_string(maxnum);

        left = idx + 1;
        right = number.size() - (--cnt);
    }
    return answer;
}