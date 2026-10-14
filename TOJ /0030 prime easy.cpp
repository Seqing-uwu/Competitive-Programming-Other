// tags: bitset,
// Time Complexity: O(N)

#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;

const int max_N = 1000000;
bitset<max_N + 5> is_not_primes;
vector<int> primes;

void create_primes_table() {
    is_not_primes[0] = is_not_primes[1] = 1;
    primes.push_back(2);
    // Euler's Sieve
    for (int i = 3; i <= max_N; i += 2) { // 只考慮奇數
        if (!is_not_primes[i]) {
            primes.push_back(i);
        }
        for (int p : primes) {
            if (p == 2) continue; // 跳過 2 的倍數
            if (i * p > max_N) break; // 溢出不考慮
            is_not_primes[i * p] = 1; // 標記合數
            if (i % p == 0) break; // 確保每個只被篩一次
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    create_primes_table();

    int N;
    while (cin >> N) {
        if (N < 2) {
            cout << "0\n";
            continue;
        }
      
        auto it = upper_bound(primes.begin(), primes.end(), N);
        cout << distance(primes.begin(), it) << "\n";
    }
    return 0;
}
