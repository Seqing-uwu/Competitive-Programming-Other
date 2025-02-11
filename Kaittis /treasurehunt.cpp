#include <iostream>
using namespace std;

char map[250][250];
bool visited[250][250];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	
	int r, c;
	cin >> r >> c;
	
	for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++) {
			cin >> map[i][j];
			visited[i][j] = false;
		}
	}
	
	int count = 0, x = 0, y = 0;
	
	while (true) {
		if ((x < 0 || x >= r) || (y < 0 || y >= c)) {
			cout << "Out\n";
			break;
		}
		if (map[x][y] == 'T') {
			cout << count << "\n";
			break;
		}
		if (visited[x][y] == true) {
			cout << "Lost\n";
			break;
		}
		
		visited[x][y] = true;
		count++;
		
		if (map[x][y] == 'N') x--;
		else if (map[x][y] == 'S') x++;
		else if (map[x][y] == 'E') y++;
		else if (map[x][y] == 'W') y--;
	}
	
    return 0;
}
