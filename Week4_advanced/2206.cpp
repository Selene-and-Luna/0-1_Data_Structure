#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
vector<vector<bool> > v;
int n, m;

bool safe(int y, int x) {
    return y < n && y > -1 && x < m && x > -1;
}

int BFS() {
    bool chk[1002][1002][2]; // y, x, broke or not
    int dy[] = {1, -1, 0, 0}, dx[] = {0, 0, 1, -1};
    queue<tuple<int, int, int, bool>> q; // y, x, dist, tf
    chk[0][0][0] = 1; chk[0][0][1] = 1;
    q.push({0, 0, 1, 0});
    while(!q.empty()) {
        tuple<int, int, int, bool> tmp = q.front();
        q.pop();
        int y = get<0>(tmp), x = get<1>(tmp), dist = get<2>(tmp);
        bool ox = get<3>(tmp);
        if(y == n - 1 && x == m - 1)
            return dist;
        for(int i = 0; i < 4; i++) {
            int cy = y + dy[i], cx = x + dx[i];
            if(safe(cy, cx) && !chk[cy][cx][ox]) {
                chk[cy][cx][ox] = 1;
                if(!ox) {
                    if(!v[cy][cx])
                        q.push({cy, cx, dist + 1, 0});
                    else
                        q.push({cy, cx, dist + 1, 1});
                }
                else if(ox && !v[cy][cx])
                    q.push({cy, cx, dist + 1, 1});
            }
        }
    }  
    return -1;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        vector<bool> tmp;
        for(int j = 0; j < m; j++) {
            char c;
            cin >> c;
            tmp.push_back(c - '0');
        }
        v.push_back(tmp);
    }
    cout << BFS();
}