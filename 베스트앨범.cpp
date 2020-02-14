#include <string>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

struct user_pair
{
    string name;
    int index;
    int sum;
};
// �帣���� ������ȣ, ��Ʈ���� ��
vector<list<pair<int,int>>> table(10000);
// �帣�� �̸�, table�� index�� �ش�Ǵ� �� �帣�� ��ȣ, �� �帣�� �� ��Ʈ���ּ�
vector<user_pair> genre_names;

bool compare(user_pair a,user_pair b)
{
    return a.sum>b.sum;
}

bool compare2(pair<int,int> a,pair<int,int> b)
{
    if(a.second==b.second){return a.first<b.first;}
    return a.second>b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    for(int i=0;i<int(genres.size());i++)
    {
        string genre=genres[i];
        bool isnt=true;
        // �̹� �ִ� �帣���� ã��
        for(int j=0;j<int(genre_names.size());j++)
        {
            // ������ �ֱ�
            if(genre==genre_names[j].name)
            {
                isnt=false;
                genre_names[j].sum+=plays[i];
                table[genre_names[j].index].push_back({i,plays[i]});
            }
        }
        // ������ �߰��ϰ� �ֱ�
        if(isnt)
        {
            int idx=int(genre_names.size());
            genre_names.push_back({genre,idx,plays[i]});
            table[idx].push_back({i,plays[i]});
        }
    }
    
    sort(genre_names.begin(),genre_names.end(),compare);
    
    for(int i=0;i<int(genre_names.size());i++)
    {
        list<pair<int,int>> musiks=table[genre_names[i].index];
        musiks.sort(compare2);
        list<pair<int,int>>::iterator lt=musiks.begin();
        if(int(musiks.size())==1){ answer.push_back((*lt).first);}
        else
        {
            answer.push_back((*lt++).first);
            answer.push_back((*lt).first);
        }
    }
    return answer;
}