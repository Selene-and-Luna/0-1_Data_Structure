#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(pair<string, int> a, pair<string, int> b) {
    return a.second < b.second;
}

int main() {
    map<string, int> sugang;
    int k, l;
    cin >> k >> l;
    for(int i = 0; i < l; i++) {
        string num;
        cin >> num;
        if(sugang.find(num) != sugang.end()) {
            sugang.erase(num);
            sugang.insert({num, i});
        }
        else
            sugang.insert({num, i});
    }

    vector<pair<string, int>> v(sugang.begin(), sugang.end());
    sort(v.begin(), v.end(), compare);

    int idx = 0;
    while(idx < v.size() && idx < k)
        cout << v[idx++].first << '\n';
}