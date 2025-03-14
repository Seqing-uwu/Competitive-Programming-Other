#include <iostream>
using namespace std;

int a[1048], temp[6666];

void merge(int p, int q) {
	
	int mid = (p+q)/2;
	int i, j, k;
	for (i=p, j=mid+1, k=p; k<=q; k++) {
		
		if (i > mid) {
			temp[k] = a[j];
			j++;
		} else if (j > q) {
			temp[k] = a[i];
			i++;
		} else if (a[i] > a[j]) {
			temp[k] = a[i];
			i++;
		} else {
			temp[k] = a[j];
			j++;
		}
	}
}

void msort(int p, int q) {
	if (p == q) return;
	
	int mid = (p+q)/2;
	
	for (int i=p; i<=q; i++) {
		for (int j=i; j>0 && a[j]<a[j-1]; j++) {
			swap(a[j], a[j-1]);
		}
	}
	
	msort(p, mid);
	msort(mid+1, q);
	merge(p, q);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n; cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	
	msort(0, n-1);
	
	for (int i=0; i<n; i++) {
		cout << temp[i] << "\n";
	}
	
	return 0;
}
