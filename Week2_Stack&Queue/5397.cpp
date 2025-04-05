#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void move_stack(stack<char> *left, stack<char> *right, char c) {
    if(c == '<') {
        if(!(left->empty())) {
            right->push(left->top());
            left->pop();
        }
    }
    else if(c == '>') {
        if(!(right->empty())) {
            left->push(right->top());
            right->pop();
        }
    }
    else if(c == '-') {
        if(!(left->empty()))
            left->pop();
    }
    else
        left->push(c);
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s; 
        cin >> s;
        stack<char> left, right;
        for(char c : s)
            move_stack(&left, &right, c);
        
        while(!(right.empty())) {
            left.push(right.top());
            right.pop();
        }

        while(!(left.empty())) {
            right.push(left.top());
            left.pop();
        }

        while(!(right.empty())) {
            cout << right.top();
            right.pop();
        }
        cout << '\n';
    }
}