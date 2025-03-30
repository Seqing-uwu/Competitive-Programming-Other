#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	string s;
	
	while (cin >> n) {
		cin.ignore();
		getline(cin, s);
		
		int len = s.size();
		for (int p=0; p<n; p++) {
			for (int i=p; i<len; i+=n) {
				cout << s[i];
			}
		}
		cout << "\n";
	}
	return 0;
}
