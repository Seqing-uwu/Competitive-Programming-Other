#include<iostream>
using namespace std;

long long C(int n, int r) {
	long long a = 1, b = 1;
	
	for (int i=r+1; i<=n; i++) {
		a *= i;
		b *= (i-r);
		if (a % (i-r) == 0) {
			a /= (i-r);
			b /= (i-r);
		}
	}
	return a / b;
}

int main() {
	int n, r;
	cin >> n >> r;

  // 數學上 C(n取r) r<0 與 r>n 根本沒意義, 在這邊搞人很有趣?
	if (r <= 0 || r > n) {
		cout << "0\n";
		return 0;
	} else if (n == r) {
		cout << "1\n";
		return 0;
	}
	
	cout << C(n, r) << "\n";
	return 0;
}
