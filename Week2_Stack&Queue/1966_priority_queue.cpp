#include <iostream>
#include <queue>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--){
        int n,m;
        priority_queue<int> q;
        queue<pair<int,int>> printer_queue;
        cin >> n >> m;
        for(int i=0; i<n; i++){
            int u;
            cin >> u;
            printer_queue.push({i,u});
            q.push(u);
        }
        int r=0;
        while(!printer_queue.empty()){
            int index=printer_queue.front().first;
            int importance=printer_queue.front().second;
            printer_queue.pop();
            if(q.top()==importance){
                q.pop();
                r++;
                if(index==m){
                cout << r << '\n';
                break;
                }
            }
            else
                printer_queue.push({index,importance});
        }
    }
}