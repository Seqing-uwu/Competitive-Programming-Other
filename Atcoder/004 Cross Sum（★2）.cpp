#include<iostream>
using namespace std;

int a[2025][2025], b[2025][2025];
int sumH[2025] = {0}, sumW[2025] = {0};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int H, W; cin >> H >> W;
	for (int i=0; i<H; i++) {
		for (int j=0; j<W; j++) {
			cin >> a[i][j];
			sumH[i] += a[i][j];
			sumW[j] += a[i][j];
		}
	}
	
	for (int i=0; i<H; i++) {
		for (int j=0; j<W; j++) {
			b[i][j] = sumH[i] + sumW[j] - a[i][j];
			
			if (j == 0) cout << b[i][j];
			else cout << " " << b[i][j];
		}
		cout << "\n";
	}
	
	return 0;
}
