#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, arr[25][25], chk[25][25], cnt;

bool safe(int y, int x) {
    return y>=0 && y<n && x>=0 && x<n;
}

void dfs(int y, int x){
    chk[y][x] = 1;
    cnt++;
    int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
    for(int i = 0; i < 4; i++)
        if(safe(y + dy[i], x + dx[i]) && arr[y +dy[i]][x + dx[i]] && !chk[y + dy[i]][x + dx[i]])
            dfs(y + dy[i], x + dx[i]);
}

int main(){
    cin >> n;
     
    for(int i=0; i<n; i++)
         for(int j=0; j<n; j++)
             scanf("%1d", &arr[i][j]);
     
    vector<int> ans;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            if(arr[i][j] == 1 && !chk[i][j]){
                cnt = 0;
                dfs(i, j);
                ans.push_back(cnt);
            }
        }
    
    cout << ans.size() << '\n';
    
    sort(ans.begin(), ans.end());
    for(int i=0; i<ans.size(); i++)
        cout << ans[i] << '\n';
}