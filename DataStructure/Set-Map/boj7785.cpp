#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<string,bool> giggle;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	string name,attend;
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> name >> attend;
		if(attend == "enter")
			giggle[name] = true;
		else
			giggle[name] = false;
	}
	vector<string> pp;
	for(auto it : giggle) {
		if(it.second==true)
			pp.push_back(it.first);
	}
	for(int i=pp.size()-1; i>=0; i--)
		cout << pp[i] << '\n';
}
//회사에 있는 사람