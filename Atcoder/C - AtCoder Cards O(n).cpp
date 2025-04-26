#include <iostream>
using namespace std;

int sa[30], ta[30];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string s, t;
	cin >> s >> t;
	int n = s.size();
	
	for (int i=0; i<n; i++) {
		if (s[i] == '@') sa[26]++;
		else sa[ s[i] - 'a' ]++;
		
		if (t[i] == '@') ta[26]++;
		else ta[ t[i] - 'a' ]++;
	}
	
	for (int i=0; i<27; i++) {
		if (i == 0 || i == 2 || i == 3 || i == 4 || i == 14 || i == 17 || i == 19) {
			if (sa[i] > ta[i]) ta[26] -= sa[i] - ta[i];
			else if (sa[i] < ta[i]) sa[26] -= ta[i] - sa[i];
			
			if (sa[26] < 0 || ta[26] < 0) {
				cout << "No\n";
                return 0;
			}
		}
		else {
			if (sa[i] != ta[i]) {
				cout << "No\n";
                return 0;
			}
		}
	}

	cout << "Yes\n";
	return 0;
}
