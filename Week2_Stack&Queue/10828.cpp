#include <iostream>
#include <stack>
using namespace std;

void stack_order(string c, stack<int> *s) {
    if (c == "push") {
        int p;
        cin >> p;
        s->push(p);
    }
    else if (c == "pop") {
        if (s->empty())
            cout << -1 << '\n';
      
        else {
            cout << s->top() << '\n';
            s->pop();
        }
    }
    else if (c == "size")
      cout << s->size() << '\n';
    
    else if (c == "empty")
      cout << s->empty() << '\n';
    
    else if (c == "top") {
      if (s->empty()) cout << -1 << '\n';
      else cout << s->top() << '\n';
    }
}

int main() {
    int n;
    string c;
    stack<int> s;
    cin >> n;
    while (n--) {
        cin >> c;
        stack_order(c, &s);
    }
}