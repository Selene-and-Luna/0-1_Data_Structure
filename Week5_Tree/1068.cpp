#include <iostream>
#include <vector>
using namespace std;
int del, root;
vector<int> tree[51];

int dfs(int chk) {
    int num_of_child = 0;
    for(int k : tree[chk])
        if(del != k) 
            num_of_child += dfs(k);
    
    if(num_of_child)  return num_of_child;
    else  return 1;
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if(t == -1)
            root=i;
        else
            tree[t].push_back(i);
    }
    cin >> del;
    if(del!=root)  cout << dfs(root);
    else  cout << 0;
}