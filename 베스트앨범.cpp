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
// 장르별로 고유번호, 스트리밍 수
vector<list<pair<int,int>>> table(10000);
// 장르의 이름, table의 index에 해당되는 한 장르의 번호, 한 장르의 총 스트리밍수
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
        //cout<<genre<<endl;
        bool isnt=true;
        // 이미 있는 장르인지 찾기
        for(int j=0;j<int(genre_names.size());j++)
        {
            // 있으면 넣기
            if(genre==genre_names[j].name)
            {
                isnt=false;
                genre_names[j].sum+=plays[i];
                //cout<<genre<<" sum값: "<<genre_names[j].sum<<endl;
                table[genre_names[j].index].push_back({i,plays[i]});
                //cout<<genre_names[j].index<<"위치에 "<<i<<" "<<plays[i]<<" 삽입"<<endl;
            }
        }
        // 없으면 추가하고 넣기
        if(isnt)
        {
            int idx=int(genre_names.size());
            //cout<<"추가 인덱스: "<<idx<<endl;
            genre_names.push_back({genre,idx,plays[i]});
            //cout<<genre<<" "<<idx<<" "<<plays[i]<<endl;
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