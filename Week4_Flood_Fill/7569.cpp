#include <iostream>
#include <queue>
#define pb push_back
using namespace std;
int M, N, H, result;
int vx[6] = { 1,-1,0,0,0,0 }, vy[6] = { 0,0,1,-1,0,0 }, vz[6] = { 0,0,0,0,1,-1 };
int map[101][101][101];

struct tomato {
	int z, y, x;
};
queue<tomato> q;

bool safe(int z, int y, int x) {
	return z >= 0 && z < H && y >= 0 && y < N && x >= 0 && x < M;
}

void BFS() {
	while (!q.empty()) {
		int  z = q.front().z, y = q.front().y, x = q.front().x;
		q.pop();
		for (int i = 0; i < 6; i++) {
			int ux = x + vx[i], uy = y + vy[i], uz = z + vz[i];
			if (safe(uz, uy, ux) && map[uz][uy][ux] == 0) {
				map[uz][uy][ux] = map[z][y][x] + 1;
				q.push({ uz,uy,ux });
			}
		}
	}
}

int main()
{
	cin >> M >> N >> H;
	for (int i = 0; i < H; i++)
		for (int j = 0; j < N; j++)
			for (int k = 0; k < M; k++) {
				cin >> map[i][j][k];
				if (map[i][j][k] == 1)    q.push({ i,j,k });
			}
	BFS();
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (map[i][j][k] == 0) {
					cout << -1;
					return 0;
				}
				if (result < map[i][j][k])  result = map[i][j][k];
			}
		}
	}
	cout << result - 1;
}