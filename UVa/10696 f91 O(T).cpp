#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	while (cin >> n && n != 0) {
		int ans;
    // lol 騙遞迴
		if (n > 100) ans = n-10;
		else ans = 91;
		
		cout << "f91(" << n << ") = " << ans << "\n";
	}
	
	return 0;
}
