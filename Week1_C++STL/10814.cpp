#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool com(pair<int, string> y, pair<int, string> x) {
    return y.first < x.first;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, string>> v;
    for (int i = 0; i < n; i++) {
        int k;
        string s;
        cin >> k >> s;
        v.push_back({k, s});
    }
    stable_sort(v.begin(), v.end(), com);
    for (auto a : v) // 귀차니
        cout << a.first << ' ' << a.second << '\n';
}