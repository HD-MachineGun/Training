#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int left=1, right=distance, MAX=-1;
    // �̺�Ž���� ���ĵǾ��־�� ��
    sort(rocks.begin(),rocks.end());
    // ������ ������ �߰�
    rocks.push_back(distance);
    
    // ���������� �Ÿ��� mid������ ��� ������ ����
    // �� ���� �Ŀ� �ٸ������� �ּڰ� ã��
    // ��������� �������� �Ÿ��� �����뼱�� �̺�Ž��
    while(left<=right)
    {
        int cnt=0, prev=0, mid=(left+right)/2, MIN=1000000001;
        for(int i=0;i<rocks.size();i++)
        {
            if(rocks[i]-prev<=mid){ cnt++; }
            else
            {
                MIN=min(MIN,rocks[i]-prev);
                prev=rocks[i];
            }
        }
        // ������ ���������� n���� ���� ������ �������� �� ����
        // �� �� ���� ū �ּڰ� ã��
        if(cnt<=n)
        { 
            MAX=max(MAX,MIN); 
            left=mid+1;
        }
        else{ right=mid-1; }
    }
    return MAX;
}