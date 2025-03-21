#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	for (int k=1; k<=n; k++) {
		int g; cin >> g;
		long long ans = 0;
		
		for (int i=0; i<g; i++) {
			long long x; cin >> x;
			ans ^= x;
		}
		
		cout << "Case #" << k << ": " << ans << "\n";
	}
	
	return 0;
}
