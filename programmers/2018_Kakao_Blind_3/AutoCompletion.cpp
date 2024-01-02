#include <bits/stdc++.h>
using namespace std;

struct Trie {
    bool finish;
    int child;
    Trie* next[26];
    
    Trie() : finish(false) {
        finish=false; child=0;
        memset(next, 0, sizeof(next));
    }
    
    void insert(const char *key) {
        child++;
        if(!(*key)) finish = true;
        else {
            int cur = *key-'a';
            if (!next[cur]) next[cur] = new Trie();
            next[cur]->insert(key+1);
        }
    }
    
    int find(const char *key, int depth) {
        if(child==1 || !(*key)) return depth;
        int cur = *key-'a';
        return next[cur]->find(key+1, depth+1);
    }
};

int solution(vector<string> words) {
    int answer=0;
    Trie *root = new Trie();
    for(string str : words) root->insert(str.c_str());
    for(string str : words) answer+=root->find(str.c_str(),0);

    return answer;
}