#include <iostream>
using namespace std;

bool solve(const string &s) {
	int n = s.size();
	
	for (int i=n-1; i>=0; i--) {
		if (s[i] == 'N') {
			solve(s.substr(i, n-i));
		}
		else if (s[i] == 'C' || s[i] == 'D' || s[i] == 'E' || s[i] == 'I') {
			
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string s;
	while (cin >> s) {
		bool isSentence = solve(s);
		
		if (isSentence) cout << "YES\n";
		else cout << "NO\n";
	}
	
	return 0;
}
// p q r s t u v w x y z
// N C D E I
