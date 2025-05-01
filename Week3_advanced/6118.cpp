#include <iostream>
#include <queue>
using namespace std;

void BFS(vector<int> v[]) {
    int cnt = 0, dist = 0, min_idx = 0;
    bool chk[20001] = {0,};
    queue<pair<int, int> > q; // idx, dist
    q.push({1, 0});
    chk[1] = 1;
    while(!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        bool tf = 0;
        for(int i : v[p.first]) {
            if(!chk[i]) {
                tf = 1;
                chk[i] = 1;
                q.push({i, p.second + 1});
            }
        }
        if(!tf) {
            if(p.second > dist) {
                cnt = 1;
                min_idx = p.first;
                dist = p.second;
            }
            else if(p.second == dist) {
                min_idx = min_idx < p.first ? min_idx : p.first;
                ++cnt;
            }
        }
    }
    cout << min_idx << ' ' << dist << ' ' << cnt;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v[20001];
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    BFS(v);
}