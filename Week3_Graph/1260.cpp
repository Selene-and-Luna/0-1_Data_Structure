#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> t(1001);
int chk1[1001], chk2[1001];

void dfs(int vtx){
    chk1[vtx] = 1;
    cout << vtx << ' ';
    for (int i = 0; i < t[vtx].size(); i++) {
        int next = t[vtx][i];
        if (!chk1[next])
            dfs(next);
    }
}

void bfs(int vtx){
    queue<int> q;
    q.push(vtx);
    chk2[vtx] = 1;
    while (!q.empty()) {
        int vtx = q.front();
        q.pop();
        cout << vtx << ' ';
        for (int i = 0; i < t[vtx].size(); i++) {
            int next = t[vtx][i];
            if (!chk2[next]) {
                q.push(next);
                chk2[next] = chk2[vtx] + 1;
            }
        }
    }
}

int main() {
    int n, m, v;
    cin >> n >> m >> v;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        t[x].push_back(y);
        t[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
        sort(t[i].begin(), t[i].end());
    
    dfs(v);
    cout << '\n';
    bfs(v);
}