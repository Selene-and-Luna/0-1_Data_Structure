#include <iostream>
#include <queue>
using namespace std;

int main() {
    while(1) {
        int w, h;
        cin >> w >> h;
        if(!w && !h)
            return 0;
        bool arr[51][51], chk[51][51] = { 0, };
        for(int i = 0; i < h; i++)
            for(int j = 0; j < w; j++)
                cin >> arr[i][j];
        
        int cnt = 0;
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                if(!chk[i][j] && arr[i][j]) {
                    queue<pair<int, int> > q;
                    int vy[8] = {1, -1, 0, 0, 1, -1, 1, -1}, vx[8] = {0, 0, 1, -1, 1, -1, -1, 1};
                    chk[i][j] = 1;
                    q.push({i,j});
                    while(!q.empty()) {
                        for(int k = 0; k < 8; k++) {
                            int a = q.front().first + vy[k], b = q.front().second + vx[k];
                            if(a < 0 || b < 0 || a >= h || b >= w)
                                continue;
                            if(!chk[a][b] && arr[a][b]) {
                                q.push({a, b});
                                chk[a][b] = 1;
                            }
                        }
                        q.pop();
                    }
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';
    }
}