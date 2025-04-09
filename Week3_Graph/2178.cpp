#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, m, v[101][101], l[101][101];
bool chk[101][101];
int vx[4] = { 0,0,1,-1 };
int vy[4] = { 1,-1,0,0 };

bool safe(int y, int x) { 
	return y >= 0 && y < n && x >= 0 && x < m;
}

void bfs(int y,int x) {
	chk[y][x] = 1;
	l[y][x] = 1;
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
            int dy = y + vy[i], dx = x + vx[i];
			if (safe(dy, dx)) {
				if (v[dy][dx] == 1 && chk[dy][dx] != 1) {
					l[dy][dx] = l[y][x] + 1;
					chk[dy][dx] = 1;
					q.push(make_pair(dy, dx));
				}
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			scanf("%1d", &v[i][k]);
		}
	}
	bfs(0, 0);
	cout << l[n - 1][m - 1];
}
