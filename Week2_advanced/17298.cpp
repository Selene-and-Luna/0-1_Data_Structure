#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int result[1000001];

int main() {
    int n;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        v.push_back(t);
    }
    stack<pair<int, int> > st; // val, idx
    for(int i = 0; i < n; i++) {
        if(i && v[i] > st.top().first) {
            while(!st.empty() && st.top().first < v[i]) {
                result[st.top().second] = v[i];
                st.pop();
            }
        }
        st.push({v[i], i});
    }
    for(int i = 0; i < n; i++) {
        if(!result[i])
            cout << "-1 ";
        else
            cout << result[i] << ' ';
    }
}