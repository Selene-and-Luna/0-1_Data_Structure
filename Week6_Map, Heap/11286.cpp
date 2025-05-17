#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int main() {
    int n;
    priority_queue<int,vector<int>,greater<int>> plus_q;
    priority_queue<int,vector<int>> minus_q;
    cin >> n;
    for(int i=0; i<n; i++){
        int t;
        cin >> t;
        if(!t) {
            if(plus_q.empty() && minus_q.empty())  cout << 0 << '\n';
            else if(plus_q.empty()){
                cout << minus_q.top() << '\n';
                minus_q.pop();
            }
            else if(minus_q.empty()) {
                cout << plus_q.top() << '\n';
                plus_q.pop();
            }
            else {
                if(abs(minus_q.top()) <= plus_q.top()) {
                    cout << minus_q.top() << '\n';
                    minus_q.pop();
                }
                else {
                    cout << plus_q.top() << '\n';
                    plus_q.pop();
                }
            }
        }
        else {
            if(t>0)  plus_q.push(t);
            else  minus_q.push(t);
        }
    }
}