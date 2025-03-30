#include <iostream>
using namespace std;

const int N = 23;
int a[N];

int diffs(int n) {
	while (n > 0) {
		for (int i=0; i<=n-1; i++) {
			a[i] = a[i+1] - a[i];
		}
		n--;
	}
	
	return a[0];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int k;
	cin >> k;
	
	while (k--) {
		int n;
		cin >> n;
		
		for (int i=0; i<=n; i++) {
			cin >> a[i];
		}
		
		cout << diffs(n) << "\n";
	}
	
	return 0;
}
