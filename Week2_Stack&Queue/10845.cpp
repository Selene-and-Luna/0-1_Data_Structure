#include <iostream>
#include <queue>
using namespace std;

void queue_order(string s, queue<int> *q) {
    if (s == "push") {
        int k;
        cin >> k;
        q->push(k);
    }
    else if (s == "pop") {
        if (q->empty())
            cout << -1 << "\n";
        
        else {
            cout << q->front() << "\n";
            q->pop();
        }
    }
    else if (s == "size")
        cout << q->size() << "\n";
    
    else if (s == "empty")
        cout << q->empty() << "\n";
   
    else if (s == "front") {
        if (q->empty())
            cout << -1 << "\n";
        else
            cout << q->front() << "\n";
    }
    else if (s == "back") {
        if (q->empty())
            cout << -1 << "\n";
        else
            cout << q->back() << "\n";
    }

}

int main() {
    int n, k;
    string s;
    cin >> n;
    queue<int> q;
    while(n--) {
        cin >> s;
        queue_order(s, &q);
    }
}