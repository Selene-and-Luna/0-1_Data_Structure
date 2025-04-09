#include <iostream>
#include <queue>
using namespace std;

void solve(vector<int> *truck, int w, int l) {
    queue<int> q;
    int weight = 0, time_spend = 0;
    for(int i = 0; i < w; i++)
        q.push(0);

    vector<int>::iterator itr = truck->begin();
    while(itr != truck->end()) {
        weight -= q.front();
        q.pop();
        ++time_spend;
        if(weight + *itr <= l) {
            q.push(*itr);
            weight += *(itr++);
        }
        else
            q.push(0);
    }
    while(!q.empty() && weight > 0) {
        weight -= q.front();
        q.pop();
        ++time_spend;
    }
    cout << time_spend;
}

int main() {
    int n, w, l;
    cin >> n >> w >> l;
    vector<int> truck;
    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        truck.push_back(t);
    }

    solve(&truck, w, l);
}