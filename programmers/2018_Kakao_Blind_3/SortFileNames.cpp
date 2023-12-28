#include <bits/stdc++.h>

using namespace std;

typedef struct myFile {
    string head;
    string number;
    string tail;
} myFile;

vector<myFile> v;

int cmp(myFile a, myFile b) {
    string temp_a,temp_b;
    for(char c : a.head) temp_a+=toupper(c); for(char c : b.head) temp_b+=toupper(c);
    if(temp_a != temp_b) return temp_a<temp_b;
    if(stoi(a.number) != stoi(b.number)) return stoi(a.number)<stoi(b.number);
    return 0;
}

void insertFile(vector<string> files) {
    for(string str : files) {
        myFile f;
        int i=0;
        while(str[i]) { if(isdigit(str[i])) break; f.head+=str[i++]; }
        while(str[i]) { if(!isdigit(str[i]) || f.number.length()>=5) break; f.number+=str[i++]; }
        f.tail=str.substr(i);
        v.push_back(f);
    }
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    insertFile(files);
    stable_sort(v.begin(),v.end(),cmp);
    for(myFile f : v)
        answer.push_back(f.head+f.number+f.tail);
    return answer;
}