#include <iostream>
using namespace std;

long long bigmod(long long b, long long p, long long m) {
	long long res = 1;
	b %= m;
	
	while (p > 0) {
		if (p % 2 == 1) {
			res = ( (res % m) * (b % m) ) % m;
		}
		
		b = ( (b%m) * (b%m) ) % m;
		p /= 2;
	}
	
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int b, p, m;
	while (cin >> b >> p >> m) {
		cout << bigmod(b, p, m) << "\n";
	}
	
	return 0;
}
