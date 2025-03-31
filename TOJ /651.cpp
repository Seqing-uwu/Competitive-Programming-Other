#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	int i=1;
	// ??? 為什麼錢可以是負的
	if (n < 1) i = n+1;
	
	while (n > 0) {
		i++;
		n -= i;
	}
	
	cout << i << "\n";
	
	return 0;
}
