#include <iostream>
#include <vector>
using namespace std;
#define pb push_back

vector<pair<char, char> > v(30);

void preOrder(int vtx) {
    char tmp = vtx + 'A';
    cout << tmp;
    if(v[vtx].first != '.') preOrder(v[vtx].first - 'A');
    if(v[vtx].second != '.') preOrder(v[vtx].second - 'A');
}

void inOrder(int vtx) {
    char tmp = vtx + 'A';
    if(v[vtx].first != '.') inOrder(v[vtx].first - 'A');
    cout << tmp;
    if(v[vtx].second != '.') inOrder(v[vtx].second - 'A');
}

void postOrder(int vtx) {
    char tmp = vtx + 'A';
    if(v[vtx].first != '.') postOrder(v[vtx].first - 'A');
    if(v[vtx].second != '.') postOrder(v[vtx].second - 'A');
    cout << tmp;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char vtx, a, b;
        cin >> vtx >> a >> b;
        v[vtx - 'A'] = {a, b};
    }
    preOrder(0);
    cout << '\n';
    inOrder(0);
    cout << '\n';
    postOrder(0);
}