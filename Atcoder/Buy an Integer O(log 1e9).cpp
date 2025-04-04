#include <iostream>
using namespace std;

long long A, B, X;
long long biggest_N = 0; // 紀錄最大的 N

void found_biggest_N(int l, int r) {
	if (l > r) return; // 終止條件
	
	int N = (l+r)/2; // 取中點為 N
	int t = N;
	int N_digits = 0;
	while (t > 0) {
		t /= 10;
		N_digits++;
	}
	
	long long res = A * N + B * N_digits;
	if (l == r && X >= res) { // 如果只剩一個數字且滿足條件, 則紀錄最大值並終止
		biggest_N = N;
		return;
	}
	else if (X >= res) { // 假如 X > res 代表找到 N 滿足條件
		biggest_N = N;
		found_biggest_N(N+1, r); // 並且繼續找是否有更大的整數滿足條件
	}
	else found_biggest_N(l, N-1); // 沒有則繼續找
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> A >> B >> X;
	
	found_biggest_N(1, 1000000000);
	cout << biggest_N << "\n";
	return 0;
}
