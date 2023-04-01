#include <iostream>
#include <stack>
#include <cctype>
using namespace std;


int main() {
    string notation, result = "";
    cin >> notation;
    
    stack<char> s;
    for (auto c : notation) {
        if (isalpha(c) != 0) {
            result += c;
        } 
        else {         
            if (c == '(') {
                s.push(c);
            }
            else if (c == '*' || c == '/') {
                while (!s.empty() && (s.top() == '*' || s.top() == '/')) {
                    result += s.top();
                    s.pop();
                }
                s.push(c);
            }
            else if (c == '+' || c == '-') {
                while (!s.empty() &&  s.top() != '(') {
                    result += s.top();
                    s.pop();
                }
                s.push(c);
            }
            else if (c == ')') {
                while (!s.empty() && s.top() != '(') {
                    result += s.top();
                    s.pop();
                }
                s.pop();
            }
        }
    }

    while (!s.empty()) {
        result += s.top();
        s.pop();
    }

    cout << result << endl;
}