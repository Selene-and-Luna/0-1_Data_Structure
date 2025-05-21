#include <iostream>
#include <queue>
using namespace std;

int n, m;
bool chk[501][501];
int vx[4] = { 0,0,1,-1 };
int vy[4] = { 1,-1,0,0 };
vector<vector<int>> v(501);

bool safe(int y, int x) { //한번에 때려박기
    return y >= 0 && y < n && x >= 0 && x < m && v[y][x] == 1 && chk[y][x] == 0;
}

int bfs(int y, int x) {
	int area = 1;
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	chk[y][x] = true;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			if (safe(y + vy[i], x + vx[i])) {
				chk[y + vy[i]][x + vx[i]] = true;
				q.push(make_pair(y + vy[i], x + vx[i]));
				area++;
			}
		}
	}
	return area;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int k;
			cin >> k;
			v[i].push_back(k);
		}
	}
	int area_max = 0;
	int num_area = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (v[i][j] == 1) {
				if (chk[i][j] == false)
					num_area++;
				int t = bfs(i, j);
				area_max = max(area_max, t);
			}
		}
	}
	cout << num_area << '\n' << area_max;
}