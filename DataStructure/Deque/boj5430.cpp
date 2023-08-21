#include <iostream>
#include <queue>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

deque<int> split(string input, char delimiter) {
  deque<int> result;
  istringstream ss(input);
  string temp;
  while (getline(ss, temp, delimiter)) {
    result.push_back(stoi(temp));
  }
  return result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int t; cin >> t;
  while(t--) {
    int n; string s;
    string op;
    deque<int> ac;
    bool is_error = false,is_front = true;
    cin >> op >> n >> s;
    s = s.substr(1,s.length()-2);
    ac = split(s,',');
    for(char c : op) {
      if(c == 'R') {
        if(is_front)
          is_front = false;
        else
          is_front = true;
      }
      else if(c == 'D') {
        if(ac.empty())
          is_error = true;
        else {
          if(is_front)
            ac.pop_front();
          else
            ac.pop_back();
        }
      }
    }
    if(is_error) {
      cout << "error\n";
      continue;
    }
    cout << '[';
    if(is_front) {
      for(int i=0; i<ac.size(); i++) {
        cout << ac[i];
        if(i != ac.size()-1)
          cout << ',';
      }
    }
    else {
      for(int i=ac.size()-1; i>=0; i--) {
        cout << ac[i];
        if(i != 0)
          cout << ',';
      }
    }
    cout << "]\n";
  }
}
