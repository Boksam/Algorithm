#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int t, n, result = 1e9;
vector<string> v;
vector<string> ans;
map<string, int> m;


int getDiff(string s1, string s2) {
    int diff = 0;
    for (int i = 0; i < 4; i++)
        if (s1[i] != s2[i]) diff++;
    return diff;
}


void solve1(int k) {
    if (ans.size() == 3) {
        int newRes = 0;
        newRes += getDiff(ans[0], ans[1]);
        newRes += getDiff(ans[1], ans[2]);
        newRes += getDiff(ans[0], ans[2]);
        result = min(result, newRes);
        return;
    }
    for (int i = k; i < v.size(); i++) {
        ans.push_back(v[i]);
        solve1(i + 1);
        ans.pop_back();
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while (t--) {
        cin >> n;
        string tmp;
        for (int i = 0; i < n; i++) {   // 최대 3개까지 입력
            cin >> tmp;
            if (m[tmp] < 3) {
                v.push_back(tmp);
                m[tmp]++;
            }
        }

        if (n <= 32) solve1(0);
        else result = 0;

        cout << result << '\n';
        
        v.clear();
        ans.clear();
        m.clear();
        result = 1e9;
    }
}