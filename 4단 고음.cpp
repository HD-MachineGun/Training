#include <cmath>
using namespace std;

int func(int n, int plus_cnt)
{
    int result = 0;

    // log(n)/log(3) = *�� ����
    if (n < 1 || 2 * log(n) / log(3) < plus_cnt) { return 0; }

    // �������� ������3�̰� ++�̾����
    if (n == 3 && plus_cnt == 2) { return 1; }

    // *++ �����Ǹ� �ٷιٷ� ����
    if (n % 3 == 0 && plus_cnt >= 2) { result += func(n / 3, plus_cnt - 2); }
    result += func(n - 1, plus_cnt + 1);

    return result;
}

int solution(int n) {
    return func(n - 2, 2);
}