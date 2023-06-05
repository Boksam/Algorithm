#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

string w_s, p_s;
int wsSize, psSize;

vector<int> PI;
vector<int> ans;

void getPI() {
    int j = 0;
    for (int i = 1; i < psSize; i++) {
        while (j > 0 && p_s[i] != p_s[j])
            j = PI[j - 1];
        if (p_s[i] == p_s[j])
            PI[i] = ++j;
    }
}

void KMP() {
    int j = 0;
    for (int i = 0; i < wsSize; i++) {
        while(j > 0 && w_s[i] != p_s[j])
            j = PI[j - 1];
        if (w_s[i] == p_s[j]) {
            if (j == psSize - 1) {
                ans.push_back(i - psSize + 1);
                j = PI[j];
            }
            else
                j++;
        }
    }
}

void printAns() {
    cout << ans.size() << endl;
    for (auto n : ans)
        cout << n + 1 << " ";
    cout << endl;
}

int main() {
    getline(cin, w_s);
    getline(cin, p_s);
    wsSize = w_s.size();
    psSize = p_s.size();

    PI.resize(psSize);

    getPI();
    KMP();

    printAns();

    return 0;
}