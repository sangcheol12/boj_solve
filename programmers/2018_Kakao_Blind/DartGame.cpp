#include <bits/stdc++.h>

using namespace std;

int num[4];

int solution(string dartResult) {
    int idx=1,v=0;
    for(auto i : dartResult) {
        if(isdigit(i)) v = v*10+(i-'0');
        else if(i == 'S' || i == 'D' || i == 'T') {
            if(i == 'S') num[idx] = v;
            else if(i == 'D') num[idx] = pow(v,2);
            else num[idx] = pow(v,3);
            v=0;
            idx++;
        }
        else if(i == '#') num[idx-1]*=-1;
        else num[idx-2]*=2, num[idx-1]*=2;
    }
    return num[1]+num[2]+num[3];
}