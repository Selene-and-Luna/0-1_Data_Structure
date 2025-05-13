#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

void func(int &level, vector<int> &v) {
    vector<int> result[10];
    queue<pair<int, int>> q; // level, idx
    int mid = pow(2, level - 1) - 1;
    q.push({0, mid}); // start mid
    while(!q.empty()) {
        int idx = q.front().second, cur = q.front().first;
        q.pop();
        result[cur].push_back(v[idx]);
        if(++cur != level) {
            q.push({cur, idx - (mid + 1) / pow(2, cur)});
            q.push({cur, idx + (mid + 1) / pow(2, cur)});
        }
    }
    for(int i = 0; i < level; i++) {
        for(int t : result[i])
            cout << t <<  ' ';
        cout << '\n';
    }
}

int main() {
    int level;
    vector<int> v;
    vector<int> result[10];
    cin >> level;
    for(int i = 0; i < pow(2, level) - 1; i++) {
        int t;
        cin >> t;
        v.push_back(t);
    }
    func(level, v);
}