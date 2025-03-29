#include<iostream>
using namespace std;

long long C(int n, int r) {
	long long res = 1;
	for (int i = 0; i < r; i++) {
	res = res * (n - i) / (i + 1);  // 逐步相乘相除, 防止溢位
	}
	return res;
}

int main() {
	int n, r;
	cin >> n >> r;

	// 數學上 C(n取r) r<0 與 r>n 根本沒意義, 在這邊搞人很有趣?
	if (r < 0 || r > n) {
		cout << "0\n";
		return 0;
	}
	
	cout << C(n, r) << "\n";
	return 0;
}
