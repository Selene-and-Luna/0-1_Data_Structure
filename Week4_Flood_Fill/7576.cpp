#include <iostream>
#include <queue>
using namespace std;
struct tomato {
    int y, x;
};
queue<tomato> q;
int n, m, r = 0, map[1001][1001];
int vx[4] = { 0,0,1,-1 };
int vy[4] = { 1, -1, 0, 0 };
bool safe(int y, int x) {
    return y >= 0 && y < n&& x >= 0 && x < m;
}
void bfs() {
    while (!q.empty()) {
        int y = q.front().y, x = q.front().x;
        q.pop();
        for (int i = 0; i < 4; i++) {
            if (safe(y + vy[i], x + vx[i]) && map[y + vy[i]][x + vx[i]] == 0) {
                map[y + vy[i]][x + vx[i]] = map[y][x] + 1;
                q.push({ y + vy[i],x + vx[i] });
            }
        }
    }
}
int main() {
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 1)    q.push({ i,j });
        }
    }
    bfs();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 0) {
                cout << -1;
                return 0;
            }
            if (r < map[i][j])  r = map[i][j];
        }
    }
    cout << r - 1;
}