#include <string>
#include <vector>

using namespace std;

string solution(string p) {
    if(p.length()==0){ return ""; }
    
    int left=0,right=0;
    bool correct=true;
    
    for(int i=0;i<p.length();i++)
    {
        if(p[i]=='('){ left++; }
        else{ right++; }
        
        if(right>left){ correct=false; }
        if(right==left)
        {
            string u=p.substr(0,i+1);
            string v=p.substr(i+1);
            if(correct){ return u+solution(v); }
            else
            {
                string s="("+solution(v)+")";
                u=u.substr(1); u.pop_back();
                for(int j=0;j<u.length();j++)
                {
                    if(u[j]=='('){ u[j]=')'; }
                    else{ u[j]='('; }
                }
                s+=u;
                return s;
            }
        }
    }
}