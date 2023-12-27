#include <bits/stdc++.h>

using namespace std;

vector<string> makeStrSet(string str) {
    vector<string> ret;
    for(int i=0; i<str.length()-1; i++) {
        string sub = str.substr(i,2);
        if(isalpha(sub[0]) && isalpha(sub[1])) ret.push_back(sub);
    }
    return ret;
}

int interCnt(vector<string> sub1, vector<string> sub2) {
    set<string> s;
    int cnt = 0;
    for(string str : sub1)
        if(find(sub2.begin(),sub2.end(),str)!=sub2.end()) s.insert(str);
    for(string str : s) cnt+=min(count(sub1.begin(),sub1.end(),str), count(sub2.begin(),sub2.end(), str));
    return cnt;
}

int solution(string str1, string str2) {
    int answer = 0;
    string nStr1,nStr2;
    for(int i=0; i<str1.length(); i++) if(isalpha(str1[i])) str1[i]=toupper(str1[i]);
    for(int i=0; i<str2.length(); i++) if(isalpha(str2[i])) str2[i]=toupper(str2[i]);
    vector<string> substr1 = makeStrSet(str1); vector<string> substr2 = makeStrSet(str2);
    int inter = interCnt(substr1, substr2);
    int uni = substr1.size()+substr2.size()-inter;
    if(inter==uni) return 65536;
    return 65536*inter/uni;
}