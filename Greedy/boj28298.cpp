#include <bits/stdc++.h>
using namespace std;

char tile[501][501];
int cnt[501][501][31];
char newTile[501][501];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,m,k,res=0;
  cin >> n >> m >> k;
  for(int i=0; i<n; i++)
    cin >> tile[i];
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      cnt[i%k][j%k][tile[i][j]-'A']++;
    }
  }
  int v = (n/k) * (m/k);
  for(int i=0; i<k; i++) {
    for(int j=0; j<k; j++) {
      int max_k = 0;
      for(int u=0; u<30; u++) {
        if(max_k < cnt[i][j][u]) {
          max_k = cnt[i][j][u];
          newTile[i][j] = u+'A';
        }
      }
      res += (v-max_k);
    }
  }
  cout << res << '\n';
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      cout << newTile[i%k][j%k];
    }
    cout << '\n';
  }
}