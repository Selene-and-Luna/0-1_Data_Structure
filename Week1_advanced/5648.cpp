#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> v;
    while(n--) {
        string s;
        cin >> s;
        reverse(s.begin(), s.end()); // 뒤집기!
        v.push_back(stoll(s));
    }
    sort(v.begin(), v.end());
    for(long long i : v)
        cout << i << '\n';
}
