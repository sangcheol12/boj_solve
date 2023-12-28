#include <bits/stdc++.h>

using namespace std;

vector<int> timeList;
vector<pair<int, int>> bus;
int lastTake[11];

pair<string,string> mySplit(string str, char c) {
    pair<string, string> temp;
    int i = 0;
    for(; str[i] != c; i++) temp.first+=str[i];
    i++;
    for(; i<str.length(); i++) temp.second+=str[i];
    return temp;
}

int stringToMinute(string t) {
    pair<string, string> temp = mySplit(t,':');
    return stoi(temp.first)*60 + stoi(temp.second);
}

string minuteToString(int m) {
    string str1, str2;
    str1=to_string(m/60);
    if(str1.length() == 1) str1 = "0"+str1;
    str2=to_string(m%60);
    if(str2.length() == 1) str2 = "0"+str2;
    return str1+":"+str2;
}

void takeCrew(int m) {
    int idx=0;
    for(int i : timeList) {
        while(bus[idx].first < i || bus[idx].second >= m)
            if(++idx > bus.size()) return ;
        lastTake[idx] = i;
        bus[idx].second++;
    }
}

string getRes(int m) {
    if(bus[bus.size()-1].second<m) return minuteToString(bus[bus.size()-1].first);
    return minuteToString(lastTake[bus.size()-1]-1);
}

string solution(int n, int t, int m, vector<string> timetable) {
    sort(timetable.begin(), timetable.end());
    for(int i=0; i<n; i++)
        bus.push_back({stringToMinute("09:00")+t*i,0});
    for(string i : timetable) timeList.push_back(stringToMinute(i));
    takeCrew(m);
    for(pair<int, int> i : bus) {
        cout << i.first << ' ' << i.second << '\n';
    }
    return getRes(m);
}