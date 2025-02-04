#include <iostream>
#include <cmath>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int x;
    while (cin >> x && x != 0) {
        int p = 1;
        if (x == -2147483648) {
        	cout << "31\n";
        	continue;
        }
        
        int f = 0;
        if (x<0) f = 1;
        x = abs(x);

		// 質因數分解
        for (int i = 2; i <= sqrt(x); ++i) {
            if (x % i == 0) {
				int count = 0;
				while (x % i == 0) {
					x /= i;
					count++;
				}
				if (p == 1) {
					p = count;
				} else {
					p = gcd(p, count); // 找GCD
				}
			}
		}
		if (x > 1 && p!= 1) {
            p = gcd(p, 1);
        }
        
		if (f) {
			while (p % 2 == 0) p /= 2;
		}
        cout << p << "\n";
    }
    return 0;
}
