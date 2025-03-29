#include <iostream>
using namespace std;

bool solve(const string &s) {
	int stack = 0;
	int n = s.size();
	
	for (int i=n-1; i>=0; i--) {
		if (s[i] >= 'p' && s[i] <= 'z') {
			stack++;
		}
		else if (s[i] == 'N') {
			if (stack < 1) return false;
		}
		else if (s[i] >= 'C' && s[i] <= 'I') {
			if (stack < 2) return false;
			stack--;
		}
		else {
			return false;
		}
	}
	
	return (stack == 1); // 最後應該只剩一個完整的句子
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
