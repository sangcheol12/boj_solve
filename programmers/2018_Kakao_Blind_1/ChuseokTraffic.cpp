#include <bits/stdc++.h>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;
vector<pair<int, int>> times;

void getBeginEndTime(vector<string> lines) {
    for(string str : lines) {
        string sHour,sMinu,sSec,sMsec,temp;
        int time=0;
        sHour=str.substr(11,2); sMinu=str.substr(14,2); sSec=str.substr(17,2);
        sMsec=str.substr(20,3); temp=str.substr(24); temp[temp.length()-1]=0;
        time=3000+stoi(sHour)*3600000+stoi(sMinu)*60000+stoi(sSec)*1000+stoi(sMsec);
        //cout << time-((int)(stod(temp)*1000))+1 << ' ' << time << '\n';
        times.push_back({time-((int)(stod(temp)*1000))+1,time});
    }
}

int solution(vector<string> lines) {
    int answer=0;
    getBeginEndTime(lines);
    sort(times.begin(), times.end());
    for(int i=0; i<times.size(); i++) {
        int startTime = times[i].second;
        int endTime = startTime+1000-1;
        //cout << startTime << ' ' << endTime << '\n';
        int cnt=0;
        for(auto j : times)
            if((j.first<startTime && j.second<startTime) || (j.first>endTime && j.second>endTime))
                cnt++;
        answer=max(answer,(int)lines.size()-cnt);
    }
    return answer;
}