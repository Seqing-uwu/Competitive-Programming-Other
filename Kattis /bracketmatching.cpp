#include<iostream>
using namespace std;

char getTop(string s) {
	int r = s.size()-1;
	return s[r];
}

void pop(string &s) {
	int r = s.size()-1;
	s.erase(r, 1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string s = "";
	int n; cin >> n;
	
	bool valid = true;
	char ch;
	for (int i=0; i<n; i++) {
		cin >> ch;
		
		if (ch == '(' || ch == '[' || ch == '{') {
			s += ch;
		}
		
		else if (ch == ')' || ch == ']' || ch == '}') {
			if (s == "") {
				valid = false;
			}
			
			char top = getTop(s);
			if ((top == '(' && ch == ')') || (top == '[' && ch == ']') || (top == '{' && ch == '}')) {
				pop(s);
			} else {
				valid = false;
			}
		}
		
		if (!valid) {
			cout << "Invalid\n";
			return 0;
		}
	}
	
	if (s == "") cout << "Valid\n";
	else cout << "Invalid\n";
	
	return 0;
}
