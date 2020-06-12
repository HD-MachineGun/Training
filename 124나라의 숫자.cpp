#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

string solution(int n) {
    string answer = "";
    int share,remain;
    do
    {
        share=n/3;
        remain=n%3;
        
        if(remain==0){ share--; answer+="4";}
        else{ answer+=to_string(remain); }
        
        n=share;
    }while(share!=0);
    
    reverse(answer.begin(),answer.end());
    return answer;
}