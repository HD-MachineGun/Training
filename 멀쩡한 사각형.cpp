using namespace std;

long long getGCD(long long a, long long b)
{
    if(a%b==0){ return b; }
    return getGCD(b,a%b);
}
// (w/g+h/g-1)g=w+h-g
long long solution(int w,int h) {
    long long w1=w, h1=h;
    long long answer = w1*h1-(w1+h1-getGCD(w1,h1));
    return answer;
}