#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main() {
    deque<char> dq;
    string s, bomb;
    cin >> s >> bomb;
    for(char c : s) {
        dq.push_back(c);
        if(c == bomb.back() && dq.size() >= bomb.length()) {
            string tmp = "";
            for(int i = bomb.length() - 1; i >= 0; i--) {
                char element = dq.back();
                dq.pop_back();
                tmp += element;
            }
            reverse(tmp.begin(), tmp.end());
            if(tmp != bomb)
                for(char t : tmp)
                    dq.push_back(t);
        }
    }
    if(dq.empty())
        cout << "FRULA";
    else {
        while(!dq.empty()) {
            cout << dq.front();
            dq.pop_front();
        }
    }
}