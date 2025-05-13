#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
int n, cnt;
bool chk[2001][2001];
char graph[2001][2001];

bool safe(int y, int x) {
    return !chk[y][x] && y >= 0 && x >= 0 && y < n && x < n && graph[y][x] != '#';
}

void BFS(int y, int x) {
    queue<pair<int, int> > q; // y, x
    q.push({y, x});
    chk[y][x] = 1;
    while(!q.empty()) {
        int qy = q.front().first, qx = q.front().second;
        if(graph[qy][qx] == '.') {
            ++cnt;
        }
        q.pop();
        int dx[] = { 0, 1, -1, 1, 1, -1, -1 }; // except w = y = 1, x = 0
        int dy[] = { -1, 0, 0, 1, -1, 1, -1 };
        for(int i = 0; i < 7; i++)
            if(safe(qy + dy[i], qx + dx[i])) {
                chk[qy + dy[i]][qx + dx[i]] = 1;
                q.push({qy + dy[i], qx + dx[i]});
            }
    }
}

int main() {
    cin >> n;
    int y, x;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            cin >> graph[i][j];
            if(graph[i][j] == 'F') {
                y = i;
                x = j;
            }
        }
    BFS(y, x);

    cout << cnt;
}