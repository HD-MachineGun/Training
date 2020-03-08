#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = s.length();
    for(int i=1;i<=s.length()/2;i++)
    {
        string res="";
        string temp=s.substr(0,i);
        int count=1;
        
        for(int j=i;j<=s.length();j+=i)
        {
            if(temp==s.substr(j,i))
            {
                count++;
            }
            else
            {
                if(count==1)
                {
                    res+=temp;
                }
                else
                {
                    res+=to_string(count)+temp;
                }
                temp=s.substr(j,i);
                count=1;
            }
        }
        
        int res_len=res.length();
        if(s.length()%i!=0){ res_len+=(s.length()%i); }
        answer=min(answer,res_len);
    }
    return answer;
}