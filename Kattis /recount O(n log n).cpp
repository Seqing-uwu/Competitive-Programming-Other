#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100069;
string ticket[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n = 0;
	while (getline(cin, ticket[n])) {
		if (ticket[n] == "***") break;
		n++;
	}
	
	sort(ticket, ticket+n);
	
	string winner;
	int max_vote = 0, count = 1;
	bool tie = false;
	
	for (int i=1; i<n; i++) {
		if (ticket[i] == ticket[i-1]) {
			count++;
		}
		else {
			if (count > max_vote) {
				winner = ticket[i-1];
				max_vote = count;
				tie = false;
			}
			else if (count == max_vote) {
				tie = true;
			}
			count = 1;
		}
	}
	if (count > max_vote) {
		winner = ticket[n-1];
		max_vote = count;
		tie = false;
	}
	else if (count == max_vote) {
		tie = true;
	}
	count = 1;
	
	if (tie) cout << "Runoff!\n";
	else cout << winner << "\n";
	
	return 0;
}
