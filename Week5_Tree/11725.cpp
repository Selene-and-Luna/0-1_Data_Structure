#include <iostream>
#include <vector>
using namespace std;
vector<int> tree[100001];
int arr[100001];

void dfs(int u) {
    for(int i = 0; i < tree[u].size(); i++) {
        int k = tree[u][i];
        if(arr[k] == 0){
            arr[k] = u;
            dfs(k);
        }
    }
}

int main() {
    int n;
    cin >> n;
    arr[0] = 1;
    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs(1);
    for(int i = 2; i <= n; i++)
        cout << arr[i] << '\n';
    
}