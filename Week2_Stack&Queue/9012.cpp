#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int n, r;
    cin >> n;
    string t;
    for (int i = 0; i < n; i++) {
        r = 1;
        cin >> t;
        stack<char> s;
        for (int k = 0; k < t.size(); k++) {
            if (t[k] == '(')
                s.push('(');
            else {
                if (s.empty()) {
                    r = 0;
                    break;
                }
                else
                    s.pop();
            }

        }
        if (!s.empty())
            r = 0;
        if (r == 1)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}