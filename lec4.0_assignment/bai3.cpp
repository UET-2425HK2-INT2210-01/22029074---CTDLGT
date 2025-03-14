#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s) {
    stack<char> st;
    for (size_t i = 0; i < s.length(); i++) { // Thay th? range-based loop
        char ch = s[i];
        if (ch == '(' || ch == '[' || ch == '{') {
            st.push(ch);
        } else {
            if (st.empty()) return false;
            char top = st.top();
            if ((ch == ')' && top == '(') || (ch == ']' && top == '[') || (ch == '}' && top == '{')) {
                st.pop();
            } else {
                return false;
            }
        }
    }
    return st.empty();
}

int main() {
    string s;
    cin >> s;
    if (isValid(s)) {
        cout << "Valid\n";
    } else {
        cout << "Invalid\n";
    }
    return 0;
}
