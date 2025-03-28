#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

void split(vector<string> *v, string s) {
    istringstream ist(s);
    string buffer;
    while(getline(ist, buffer, '#'))
        if(buffer.length() > 1)
            v->push_back(buffer);
}

int main() {
    int r, c;
    cin >> r >> c;
    vector<string> v;
    vector<string> result;
    for(int i = 0; i < r; i++) {
        string s;
        cin >> s;
        split(&result, s);
        v.push_back(s);
    }

    for(int i = 0; i < c; i++) {
        string tmp = "";
        for(int j = 0; j < r; j++)
            tmp += v[j][i];
        split(&result, tmp);
    }

    sort(result.begin(), result.end());
    cout << result.front();
}