#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int n;
  int dice[6];
  cin >> n;
  for(int i=0; i<6; i++)
    cin >> dice[i];
  if(n==1) {
    sort(dice,dice+6);
    int result=0;
    for(int i=0; i<5; i++)
      result += dice[i];
    cout << result;
    return 0;
  }
  int small[3];
  small[0] = min(dice[0],dice[5]);
  small[1] = min(dice[1],dice[4]);
  small[2] = min(dice[2],dice[3]);
  sort(small,small+3);
  long long result = small[0]*(5*(long long)(n-2)*(n-2)+4*(n-2)+4*((n-1)+(n-2))+4) + small[1]*(4*((n-1)+(n-2))+4) + small[2]*4;
  cout << result;
}
