#include <iostream>
using namespace std;

int hadamard(int n, int x, int y) {
	if (n == 1) return 1;
	int half = n/2;
	
	if (x < half && y < half) return hadamard(half, x, y); // 左上
	if (x >= half && y < half) return hadamard(half, x - half, y); // 右上
	if (x < half && y >= half) return hadamard(half, x, y - half); // 左下
	return -hadamard(half, x - half, y - half); // 右下 (取負)
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	int t; cin >> t;
	
	while (t--) {
		int n, x, y, w, h;
		cin >> n >> x >> y >> w >> h;
		
		for (int i=y; i<y+h; i++) {
			for (int j=x; j<x+w; j++) {
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
