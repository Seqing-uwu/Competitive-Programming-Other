#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 500;
string names[MAX];

bool comp(const string &a, const string &b) {
	char sa = a[0], sb = b[0];
	if (sa != sb) return sa < sb;
	
	char ca = a[1], cb = b[1];
	if (ca != cb) return ca < cb;
	
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N;
	while (cin >> N && N != 0) {
		for (int i=0; i<N; i++) {
			cin >> names[i];
		}
		
		stable_sort(names, names+N, comp);
		
		for (int i=0; i<N; i++) {
			cout << names[i] << "\n";
		}
		
		cout << "\n";
	}
	
	return 0;
}
