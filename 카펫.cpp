#include <string>
#include <vector>
#include <math.h>

using namespace std;

// red�� ������� �̿��� brown ���� ã�Ƴ��� ����
vector<int> solution(int brown, int red) {
    vector<int> answer;
    for(int i=1;i<=sqrt(red);i++)
    {
        if(red%i==0)
        {
            int share=red/i;
            if(brown==2*(share+i)+4)
            {
                answer.push_back(max(share+2,i+2));
                answer.push_back(min(share+2,i+2));
                break;
            }
        }
    }
    return answer;
}