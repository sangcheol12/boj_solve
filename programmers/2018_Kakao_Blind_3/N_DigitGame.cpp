#include <bits/stdc++.h>

using namespace std;

string str="0123456789ABCDEF", temp="0";

string transDeci(int num, int n) {
    string ret;
    while(num!=0) {
        ret+=str[num%n];
        num/=n;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

void getTemp(int n, int t, int m) {
    int i=0;
    while(temp.length() < t*m)
        temp+=transDeci(i++,n);
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    getTemp(n,t,m);
    cout << temp << '\n';
    for(int i=0; i<t; i++)
        answer+=temp[p-1+m*i];
    return answer;
}