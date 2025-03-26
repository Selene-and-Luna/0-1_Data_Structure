#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, i, j;
    vector<pair<int, int> > v;
    cin >> n;
    for (int k = 0; k < n; k++) {
        cin >> i >> j;
        v.push_back({ i, j });
    }
    
    sort(v.begin(), v.end());
    for (pair<int, int> p:v)
        cout << p.first << ' ' << p.second << '\n';
}