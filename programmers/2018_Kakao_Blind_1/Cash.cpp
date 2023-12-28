#include <bits/stdc++.h>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    if(!cacheSize) return cities.size()*5;
    deque<string> dq;
    for(string i : cities) {
        string data;
        for(char c : i) data+=toupper(c);
        if(find(dq.begin(), dq.end(), data) != dq.end()) {
            dq.erase(find(dq.begin(), dq.end(), data));
            answer+=1;
        } else {
            if(dq.size() >= cacheSize) dq.pop_front();
            answer+=5;
        }
        dq.push_back(data);
    }
    return answer;
}