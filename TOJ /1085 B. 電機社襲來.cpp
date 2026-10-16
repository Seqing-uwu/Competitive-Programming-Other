// 實作快的超笨方法，不要學

#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int N, Q;
    cin >> N >> Q;
    int death = 1e6 + 5;
    vector<vector<int> > drone(death);

    for (int i=0; i<N; i++) {
        int d, u; cin >> d >> u;
        drone[d].push_back(u);
    }

    for (int i=0; i<Q; i++) {
        int d, a; cin >> d >> a;
        int king_gg = 0;
        while (a > 0 && drone[d].size() > 0) {
            if (drone[d].front() > a) {
                drone[d].front() -= a;
                a = 0;
            } else {
                a -= drone[d].front();
                king_gg++;
                drone[d].erase(drone[d].begin());
            }
        }
        cout << king_gg << "\n";
    }

    return 0;
}
