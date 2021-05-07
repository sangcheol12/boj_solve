#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--) {
		stack<char> st;
		bool fail = false;
		string str;
		cin >> str;
		for(int i=0; str[i]; i++) {
			if(str[i] == '(')
				st.push('(');
			else {
				if(!st.empty())
					st.pop();
				else {
					fail = true;
					break;
				}
			}
		}
		if(!st.empty())
			fail = true;
		if(fail)
			cout << "NO" << '\n';
		else
			cout << "YES" << '\n';
	}
}
//괄호