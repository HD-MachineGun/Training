#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long fac(int n)
{
    if(n==1){ return 1; }
    return fac(n-1)*n;
}

vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> temp;
    for(int i=1;i<=n;i++){ temp.push_back(i); }
    int tsize=temp.size();
    while(tsize>5)
    {
        long long num=fac(tsize-1);
        long long share=k/num;
        long long remain=k%num;
        int index=(remain==0 ? share:share+1)-1;
        answer.push_back(temp[index]);
        temp.erase(temp.begin()+index);
        k-=share*num; tsize--;
    }
    
    sort(temp.begin(),temp.end());
    do
    {
        k--;
        if(k==0)
        {
            for(auto t: temp)
            {
                answer.push_back(t);
            }
            break;
        }
    }while(next_permutation(temp.begin(),temp.end()));
    
    return answer;
}