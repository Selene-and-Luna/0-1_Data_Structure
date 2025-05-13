#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
using namespace std;
vector<pair<int,int> > tree(100001);
int arr[100001];
int n;

int rec(int i, int sum) {
    if(i == -1)
        return sum;
    if(arr[i] != -1)
        return arr[i] + sum;
    arr[i] = rec(tree[i].first, sum + tree[i].second);
    return arr[i];
}

int main() {
    int m;
    memset(arr, -1, 4 * 100001);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> tree[i].first;
    while(m--) {
        int i, w;
        cin >> i >> w;
        tree[i].second += w;
    }

    for(int i = 1; i <= n; i++)
        rec(i, 0);

    for(int i = 1; i <= n; i++)
        cout << arr[i] << ' ';
}