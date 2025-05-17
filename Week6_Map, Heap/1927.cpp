#include <iostream>
#include <queue>
using namespace std;
int main() {
    int n;
    priority_queue<int,vector<int>,greater<int>> q;
    cin >> n;
    for(int i=0; i<n; i++){
        int t;
        cin >> t;
        if(!t) {
            if(q.empty())  cout << t << '\n';
            else {
                cout << q.top() << '\n';
                q.pop();
            }
        }
        else  q.push(t);
    }
    }