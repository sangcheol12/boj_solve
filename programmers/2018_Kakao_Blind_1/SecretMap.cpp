#include <bits/stdc++.h>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for(int i=0; i<n; i++) {
        string str="";
        int x = arr1[i]|arr2[i];
        int y = pow(2,n);
        for(int j=0; j<n; j++) {
            y/=2;
            if(x&y) str+='#';
            else str+=' ';
        }
        answer.push_back(str);
    }
    return answer;
}