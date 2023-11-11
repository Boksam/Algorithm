#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
vector<int> v;

int main() {
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    int d = round(n * 0.15);

    int sum = 0;
    for (int i = d; i < n - d; i++) {
        sum += v[i];
    }

    if (sum == 0) cout << 0 << endl;
    else cout << round((double)sum / (n - 2 * d)) << endl;
    return 0;
}