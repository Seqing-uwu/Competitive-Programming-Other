#include <iostream>
using namespace std;

// 記得 long long, debug 半天才發現 LOL
int hadamard(long long n, long long x, long long y) {
	if (n == 1) return 1;
	long long half = n/2;
	
	if (x < half && y < half) return hadamard(half, x, y); // 左上
	if (x >= half && y < half) return hadamard(half, x - half, y); // 右上
	if (x < half && y >= half) return hadamard(half, x, y - half); // 左下
	return -hadamard(half, x - half, y - half); // 右下
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	int t; cin >> t;
	
	while (t--) {
		long long n;
		int x, y, w, h;
		cin >> n >> x >> y >> w >> h;
		
		for (long long i=y; i<y+h; i++) {
			for (long long j=x; j<x+w; j++) {
				if (j == x) {
					cout << hadamard(n, j, i);
				} else {
					cout << " " << hadamard(n, j, i);
				}
			}
			cout << "\n";
		}
		cout << "\n";
	}

    return 0;
}
