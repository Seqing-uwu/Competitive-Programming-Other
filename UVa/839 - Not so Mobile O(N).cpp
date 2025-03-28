#include <iostream>
using namespace std;

bool isBanlanced;

int solve() {
	int w1, d1, w2, d2;
	cin >> w1 >> d1 >> w2 >> d2;
	
	if (w1 == 0) w1 = solve();
	if (w2 == 0) w2 = solve();
	
	// 不平衡可以直接停
	if (w1 * d1 != w2 * d2) {
		isBanlanced = false;
		return 0;
	}
	
	return w1 + w2;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	for (int i=0; i<n; i++) {
		isBanlanced = true; // 初始化
		solve();
		
		if (i != 0) cout << "\n"; // sb
		
		if (isBanlanced) cout << "YES\n";
		else cout << "NO\n";
	}
	
	return 0;
}
