#include <iostream>
#include <iomanip>
using namespace std;

int X, Y;

int blocks(int k, int x, int y) {
	// 無法構成正方形就中斷
	if (k < 1) return 0;
	
	int count = 0;
	int x0 = x - k, y0 = y - k;
	int x1 = x + k, y1 = y + k;
	
	if (x0 <= X && x1 >= X && y0 <= Y && y1 >= Y) count++;
	
	int newk = k/2;
	count += blocks(newk, x0, y0); // 左上
	count += blocks(newk, x1, y0); // 右上
	count += blocks(newk, x0, y1); // 左下
	count += blocks(newk, x1, y1); // 右下
	
	return count;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int k;
	while (cin >> k >> X >> Y && k != 0) {
		// 中心 = (1024, 1024)
		cout << setw(3) << blocks(k, 1024, 1024) << "\n";
	}
	
	return 0;
}
