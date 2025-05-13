#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
vector<int> node[100001];
vector<int> hypertube[1001];

void BFS(int &n, int &m) {
    bool chk[n + 1] = { 0, }, hyperchk[m + 1] = { 0, };
    queue<tuple<int, int, bool>> q; // node, cnt, status = 0 : station, 1 : hypertube
    q.push({1, 0, 0});
    chk[1] = 1;
    while(!q.empty()) {
        int idx = get<0>(q.front()), cnt = get<1>(q.front()) + 1;
        bool status = get<2>(q.front());
        q.pop();
        if(!status) {
            if(idx == n) {
                cout << cnt;
                return;
            }
            for(int i : node[idx])
                if(!hyperchk[i]) {
                    hyperchk[i] = 1;
                    q.push({i, cnt - 1, 1});
                }
        }
        else
            for(int i : hypertube[idx])
                if(!chk[i]) {
                    chk[i] = 1;
                    q.push({i, cnt, 0});
                }
    }
    cout << -1;
}

int main() {
    int n, k, m;
    cin >> n >> k >> m;
    for(int i = 0; i < m; i++) { // O(n^2)
        for(int j = 0; j < k; j++) {
            int t;
            cin >> t;
            node[t].push_back(i);
            hypertube[i].push_back(t);
        }
    }
    BFS(n, m);
}