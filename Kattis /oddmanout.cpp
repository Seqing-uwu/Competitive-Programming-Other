#include<iostream>
#include<algorithm>
using namespace std;

const int N = 114514;
long long c[N];

void catchtheGuy(const int &x, const int &g) {
	int sus;
	
	for (int i=0; i<g; i+=2) {
		if (i == g-1) {
			sus = c[i];
			break;
		}
		// a, a, b, b, c
		if (c[i] != c[i+1]) {
			sus = c[i];
			break;
		}
	}
	
	cout << "Case #" << x << ": " << sus << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	for (int k=1; k<=n; k++) {
		
		int g; cin >> g;
		for (int i=0; i<g; i++) {
			cin >> c[i];
		}
		
		sort(c+0, c+g);
		catchtheGuy(k, g);
	}
	
	return 0;
}
