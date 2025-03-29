#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <algorithm>
using namespace std;

// 이거 c로 푸는거 아닌거 같애
// 계산 순서대로네;;
bool find_operator(char c) {
    return c == '-' || c == '+' || c == '/' || c == 'x';
}

pair<char, int> find_num(int idx, string s) { // num, substr_size
    if(idx + 2 < s.size()) {
        if(s.substr(idx, 3) == "ONE")
            return {'1', 3};

        if(s.substr(idx, 3) == "TWO")
            return {'2', 3};

        if(s.substr(idx, 3) == "SIX")
            return {'6', 3};
    }
    if(idx + 3 < s.size()) {
        if(s.substr(idx, 4) == "ZERO")
            return {'0', 4};
        
        if(s.substr(idx, 4) == "FOUR")
            return {'4', 4};

        if(s.substr(idx, 4) == "FIVE")
            return {'5', 4};

        if(s.substr(idx, 4) == "NINE")
            return {'9', 4};
    }
    if(idx + 4 < s.size()) {
        if(s.substr(idx, 5) == "THREE")
            return {'3', 5};

        if(s.substr(idx, 5) == "SEVEN")
            return {'7', 5};

        if(s.substr(idx, 5) == "EIGHT")
            return {'8', 5};
    }
    cout << "Madness!";
    exit(0);
}

string num_to_word(long long l) {
    string s = to_string(l), result = "";
    string arr[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
    if(s[0] == '-')
        result += '-';

    for(char c : s)
        for(int i = '0'; i <= '9'; i++)
            if(i == c)
                result += arr[i - '0'];

    return result;
}

void slice(string s, vector<string> *v, vector<char> *operations) { // num, oper
    string result = "";
    int idx = 0;
    while(idx < s.length()) {
        if(!find_operator(s[idx])) {
            if(s[idx] == '=') {
                if(result != "")
                    v->push_back(result);
                if(find_operator(s[idx - 1])) {
                    cout << "Madness!";
                    exit(0);
                }
                break;
            }
            pair<char, int> p = find_num(idx, s);
            result += p.first;
            idx += p.second;
        }
        else {
            if(idx > 0) {
                if(find_operator(s[idx - 1])) {
                    cout << "Madness!";
                    exit(0);
                }
            }
            operations->push_back(s[idx++]);
            v->push_back(result);
            result = "";
        }
    }
    if(s[s.length() - 1] != '=') {
        cout << "Madness!";
        exit(0);
    }
}

void calculation(vector<string> *v, vector<char> *operations) {
    long long result = stoll((*v)[0]);
    for(int i = 0; i < operations->size(); i++) {
        char c = ((*operations)[i]);
        if(i + 1 >= v->size())
            break;
        switch(c) {
            case '+':
                result += stoll(((*v)[i + 1]));
                break;
            case '-':
                result -= stoll(((*v)[i + 1]));
                break;
            case 'x':
                result *= stoll(((*v)[i + 1]));
                break;
            case '/':
                result /= stoll((*v)[i + 1]);
                break;
            default:
                break;
        }
    }
    cout << "=\n" << num_to_word(result);
}

int main() {
    string s;
    cin >> s;
    vector<string> v; // 문자->숫자
    vector<char> operations; // 연산자
    slice(s, &v, &operations);
    if(v.empty()) {
        cout << "Madness!";
        return 0;
    }
    cout << v[0];
    if(!operations.empty()) {
        for(int i = 0; i < operations.size() - 1; i++)
            cout << operations[i] << v[i + 1];
        if(operations.size() < v.size())
            cout << operations[operations.size() - 1] << v[v.size() - 1];
    }
    calculation(&v, &operations);
}