#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int iceberg[301][301], after[301][301];
vector<int> num_of_iceberg;
int n, m, chk[301][301], cnt, year;
int vx[] = { 0,0,1,-1 }, vy[] = { 1,-1,0,0 };

bool safe(int y, int x) {
	return y >= 0 && y < n && x >= 0 && x < m && !chk[y][x] && iceberg[y][x];
}

void dfs(int y, int x) {
	chk[y][x] = 1;
	cnt++;
	for (int i = 0; i < 4; i++)
		if(safe(y + vy[i], x + vx[i]))
			dfs(y + vy[i], x + vx[i]);
}

int melting(int y, int x) {
	int melt = 0;
	for (int i = 0; i < 4; i++)
		if (iceberg[y + vy[i]][x + vx[i]] == 0)	melt++;

	return melt;
}

void iceberg_chk() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (iceberg[i][j] != 0 && !chk[i][j]) {
				cnt = 0;
				dfs(i, j);
				num_of_iceberg.push_back(cnt);
			}
}

bool chk_iceberg() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (iceberg[i][j] != 0)
                return false;
	
	return true;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> iceberg[i][j];
	
	iceberg_chk();
	while (num_of_iceberg.size() == 1) {
		memset(chk, 0, sizeof(chk));
		memset(after, 0, sizeof(after));
		num_of_iceberg.clear();
		year++;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (iceberg[i][j] != 0) {
					int melt = iceberg[i][j] - melting(i, j);
					if (melt > 0)	after[i][j] = melt;
					else    after[i][j] = 0;
				}

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)	iceberg[i][j] = after[i][j];
		iceberg_chk();
	}

	if (chk_iceberg()) cout << 0;
	else    cout << year;
}