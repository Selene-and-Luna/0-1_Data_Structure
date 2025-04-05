#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main() {
    int n, peak, result = 0;
    cin >> n;
    stack<int> height;
    while(n--) {
        int x, y;
        cin >> x >> y;
        peak = y;
        while(!height.empty() && height.top() > peak) {
            ++result;
            height.pop();
        }
        if(!height.empty() && height.top() == peak)
            height.pop();
        height.push(y);
    }
    peak = 0;
    while(!height.empty() && height.top() > peak) {
        ++result;
        height.pop();
    }
    cout << result;
}