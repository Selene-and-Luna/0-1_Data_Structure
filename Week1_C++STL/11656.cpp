#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    string s;
    cin >> s;
    vector<string> v;
    for(int i = 0; i < s.length(); i++)
        v.push_back(s.substr(i, s.length()));
    sort(v.begin(), v.end());
    for(string a : v)
        cout << a << '\n';
}