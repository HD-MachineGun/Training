#include <string>
#include <vector>

using namespace std;

int targetnum(vector<int> numbers, int target, int sum, int index)
{
    if (index == int(numbers.size()))
    {
        if (sum == target) { return 1; }
        else { return 0; }
    }
    int ret = 0;
    // +
    ret += targetnum(numbers, target, sum + numbers[index], index + 1);
    // -
    ret += targetnum(numbers, target, sum - numbers[index], index + 1);

    return ret;
}

int solution(vector<int> numbers, int target) {
    return targetnum(numbers, target, 0, 0);
}