#include <iostream>
#include <vector>
using namespace std;
vector<int> computer[101];
bool chk[101];
int virus;

void dfs(int n){
    chk[n]=1;
    for(int i=0; i<computer[n].size(); i++){
        int u=computer[n][i];
        if(chk[u]==0){
            dfs(u);
            virus++;
        }
    }
}
int main() {
    int n,m;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        computer[a].push_back(b);
        computer[b].push_back(a);
    }
    dfs(1);
    cout << virus;
}