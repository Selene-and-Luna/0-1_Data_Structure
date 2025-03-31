#include <iostream>
#include <stack>
using namespace std;

int stat(char c) {
	int tmp;
	if(c == '-' || c == '+')
		tmp = 0;
	else if(c == '*' || c == '/')
		tmp = 1;
	else if(c == '(')
		tmp = 2;
	else if(c == ')')
		tmp = 3;
	return tmp;
}

void solve(string s) {
	stack<char> st;
	for(char c : s) {
		if(c >= 65 && c <= 90)
			cout << c;
		else {
			if(st.empty())
				st.push(c);
			else {
				int t1 = stat(c), t2 = stat(st.top());
				if(t1 == 2 || t2 == 2)
					if(t1 == 3 && t2 == 2)
						st.pop();
					else
						st.push(c);
				else if(t1 == 3) {
					while(1) {
						if(st.top() == '(') {
							st.pop();
							break;
						}
						cout << st.top();
						st.pop();
					}
				}
				else if(t1 == t2) {
					int tmp = t2;
					while(tmp == t1) {
						cout << st.top();
						st.pop();
						if(st.empty())
							break;
						tmp = stat(st.top());
					}
					st.push(c);
				}
				else if(t1 < t2) {
					while(!st.empty()) {
						if(st.top() == '(')
							break;
						cout << st.top();
						st.pop();
					}
					st.push(c);
				}
				else if(t1 > t2)
					st.push(c);
			}
		}
	}
	while(!st.empty()) {
		cout << st.top();
		st.pop();
	}
}

int main() {
  string s;
	cin >> s;
	solve(s);
}
