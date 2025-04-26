#include <iostream>
using namespace std;

int main() {
	int k; cin >> k;
	
	int idx = 1;
	long long n = 7;
	
	// 排除永遠不會整除的特例
	if (k % 2 == 0 || k % 5 == 0) cout << "-1\n";
	else {
		while (n % k != 0) {
			n = n*10 + 7;
			idx++;
			// 取模循環性質
			if (n > 1000000) n %= k;
		}
		cout << idx << "\n";
	}
	return 0;
}
