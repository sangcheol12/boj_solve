#include<iostream>
#include<functional>
#include<queue>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  unsigned n,arr[100001];
  priority_queue<int> pq;
  cin >> n;
  for(int i=0; i<n; i++) {
    cin >> arr[i];
    if(arr[i]!=0) {
      pq.push(arr[i]);
    }
    else {
      if(!pq.empty()) {
        cout << pq.top() << '\n';
        pq.pop();
      }
      else {
        cout << '0' << '\n';
      }
    }
  }
}
//최대 힙