#include <iostream>
#include <cstring>
using namespace std;

string s1, s2;
string ans = "";

int main() {
    cin >> s1 >> s2;

    int s1_len = s1.length();
    int s2_len = s2.length();

    for (int i = 0; i < s1_len; i++) {
        ans += s1[i];

        if (s1[i] == s2[s2_len - 1] && ans.length() >= s2_len) {
            bool flag = true;
            for (int j = s2_len - 1; j >= 0; j--) {
                if (ans[ans.length() - 1 - (s2_len - 1) + j] != s2[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                for (int j = 0; j < s2_len; j++)
                    ans.pop_back();
            }
        }
    }

    if (ans.length() != 0)
        cout << ans << '\n';
    else
        cout << "FRULA\n";
}