#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
const int MAX_N = 10005;
int arr[MAX_N];

bool comp(int a, int b) {
	int Qa = a % M;
	int Qb = b % M;
	
	if (Qa == Qb) {
		bool odd_a = false, odd_b = false;
		// 不能寫 (a % 2 == 1), 因為有可能是負數 (餘數為-1)
		if (a % 2 != 0) odd_a = true;
		if (b % 2 != 0) odd_b = true;
		
		if (odd_a && odd_b) { // 皆為奇數
			return a > b;
		} else if (!odd_a && !odd_b) { // 皆為偶數
			return a < b;
		} else { // 一奇一偶
			return odd_a > odd_b; // 奇在偶前, 1 > 0
		}
	}
	return Qa < Qb;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	while (cin >> N >> M && (N != 0 && M != 0)) {
		
		for (int i=0; i<N; i++) {
			cin >> arr[i];
		}
		
		sort(arr, arr+N, comp); // 依照要求排序
		
		cout << N << " " << M << "\n";
		for (int i=0; i<N; i++) {
			cout << arr[i] << "\n";
		}
	}
	
	cout << "0 0\n";
	
	return 0;
}
