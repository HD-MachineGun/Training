#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

struct Trie
{
    bool finish;
    int count;
    Trie* next[26];
    Trie() : finish(false), count(1)
    {
        memset(next,0,sizeof(next));
    }
    ~Trie()
    {
        for(int i=0;i<26;i++)
        {
            if(next[i])
            {
                delete next[i];
            }
        }
    }
    void insert(const char* key)
    {
        if(*key=='\0'){ finish=true; }
        else
        {
            int cur=*key-'a';
            if(next[cur]==NULL)
            {
                next[cur]=new Trie();
            }
            else next[cur]->count++;
            next[cur]->insert(key+1);
        }
    }
    int find(const char* key)
    {
        int cur=*key-'a';
        if(*key=='?')
        { // 모든 단어가 ?일 경우
            int temp=0;
            for(int i=0;i<26;i++)
            {
                if(next[i]!=NULL)
                { 
                    temp+=next[i]->count;
                }
            }
            return temp;
        }
        if(next[cur]==NULL){ return 0; }
        if(*(key+1)=='?'){ return next[cur]->count; }
        return next[cur]->find(key+1);
    }
};

Trie* root[10001];
Trie* reroot[10001];

vector<int> solution(vector<string> words, vector<string> queries) {
    int qsize=queries.size();
    vector<int> answer(qsize,0);
    
    for(auto word: words)
    {
        int size=word.size();
        
        const char* c=word.c_str();
        if(root[size]==NULL){ root[size]=new Trie(); }
        root[size]->insert(c);
        
        string reword=word;
        reverse(reword.begin(),reword.end());
        
        const char* rec=reword.c_str();
        if(reroot[size]==NULL){ reroot[size]=new Trie(); }
        reroot[size]->insert(rec);
    }
    
    int index=0;
    for(auto query: queries)
    {
        int size=query.size();
        if(query[size-1]=='?')
        {
            const char* c=query.c_str();
            if(root[size]==NULL){ index++; continue;}
            answer[index]=root[size]->find(c);
        }
        else
        {
            string re=query;
            reverse(re.begin(),re.end());
            const char* rec=re.c_str();
            if(reroot[size]==NULL){ index++; continue; }
            answer[index]=reroot[size]->find(rec);
        }
        index++;
    }
    return answer;
}