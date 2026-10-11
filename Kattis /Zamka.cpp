// Problem: KATTIS - Zamka
// Difficultly: 1.3 EASY
// Tags: 
// Time Complexity: O(N)

#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int L, D, X;
    cin >> L >> D >> X;
    
    for (int i=L; i<=D; i++) {
        int n = i, sum = 0;
        while (n) {
            sum += n % 10;
            n /= 10;
        }
        if (sum == X) {
            cout << i << "\n";
            break;
        }
    }
    
    for (int i=D; i>=L; i--) {
        int n = i, sum = 0;
        while (n) {
            sum += n % 10;
            n /= 10;
        }
        if (sum == X) {
            cout << i << "\n";
            break;
        }
    }
    
    return 0;
}
