#include<iostream>
using namespace std;

int a[1111111];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, sumT = 0; cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		sumT += a[i];
	}
	
	long long int sumA = 0, sumB = 0;
	long long int res = 0, m = 0;
	for (int i=0; i<n; i++) {
		sumA += a[i] * a[i];
		sumB += a[i];
		
		res = sumA * (sumT - sumB);
		m = max(m, res);
	}
	
	cout << m << "\n";
	
	return 0;
}
