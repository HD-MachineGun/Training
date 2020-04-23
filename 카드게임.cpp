#include <string>
#include <vector>
#include <string.h>
#include <iostream>
using namespace std;

int cache[2001][2001];

vector<int> a;
vector<int> b;

int dp(int left_idx, int right_idx)
{
    if( left_idx > a.size() || right_idx > b.size() ){ return 0; }
    
    int& ret = cache[left_idx][right_idx];
    if(ret != -1){ return ret; }
    
    if( a[left_idx-1] > b[right_idx-1] )
    { 
        ret = b[right_idx-1] + dp( left_idx, right_idx+1 ); 
    }
    else
    {
        ret = max( dp( left_idx+1, right_idx ), dp( left_idx+1, right_idx+1 ) );
    }
    
    return ret;
}

int solution(vector<int> left, vector<int> right) {
    memset( cache, -1, sizeof(cache));
    a = left;
    b = right;
    return dp(1, 1);
}