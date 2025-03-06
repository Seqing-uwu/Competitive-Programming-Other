#include<iostream>
#include<cmath>
using namespace std;

string tile;
int level;
int x = 0, y = 0;

// (遞迴版)
void loc(int idx) {
    if (idx == level) return;
    
    if (tile[idx] == '1' || tile[idx] == '3') {
    	x += pow(2, level - idx - 1);
    }
    if (tile[idx] == '2' || tile[idx] == '3') {
    	y += pow(2, level - idx - 1);
    }
    loc(idx+1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> tile;
    level = tile.size();
    
    loc(0);
    
    cout << level << " " << x << " " << y << "\n";
    
    return 0;
}
