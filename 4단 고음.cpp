#include <cmath>
using namespace std;

int func(int n, int plus_cnt)
{
    int result = 0;

    // log(n)/log(3) = *의 개수
    if (n < 1 || 2 * log(n) / log(3) < plus_cnt) { return 0; }

    // 마지막은 음높이3이고 ++이어야함
    if (n == 3 && plus_cnt == 2) { return 1; }

    // *++ 충족되면 바로바로 없애
    if (n % 3 == 0 && plus_cnt >= 2) { result += func(n / 3, plus_cnt - 2); }
    result += func(n - 1, plus_cnt + 1);

    return result;
}

int solution(int n) {
    return func(n - 2, 2);
}