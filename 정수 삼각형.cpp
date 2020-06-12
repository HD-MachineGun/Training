#include <string>
#include <vector>
#include <string.h>

using namespace std;

int dp(vector<vector<int>>& triangle, int floor, int index)
{
    if(floor == int( triangle.size() ) - 1){ return triangle[floor][index]; }
    
    int ret=triangle[floor][index] + max( dp(triangle, floor+1, index), dp(triangle, floor+1, index+1) );
    return ret;
}
int solution(vector<vector<int>> triangle) {
    return dp(triangle, 0, 0);
}