#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string str;
int n;
vector<vector<int>> isPalin;

int main() {
    cin >> str;
    n = str.size();
    isPalin.resize(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        int idx = i;
        while (idx < n) {
            if (str[i] == str[idx]) {
                
            }

            idx++;
        }
    }
    
}