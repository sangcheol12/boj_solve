#include <bits/stdc++.h>

using namespace std;

map<string,int> stringIndex;

vector<int> solution(string msg) {
    vector<int> answer;
    int idx=1;
    for(char c='A'; c<='Z'; c++)  { string t; t+=c; stringIndex.insert({t,idx++}); }
    for(int i=0; i<msg.length();) {
        string str; str+=msg[i];
        int cur;
        while(stringIndex.count(str)) {
            cur=stringIndex[str];
            str+=msg[++i];
        }
        stringIndex[str]=idx++;
        answer.push_back(cur);
    }
    return answer;
}