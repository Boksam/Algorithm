#include <iostream>
using namespace std;

int tile[1001];

int main() {
    int N;
    cin >> N;

    tile[1] = 1;
    tile[2] = 2;
    for (int i = 3; i < 1001; i++) {
        tile[i] = (tile[i-1] + tile[i-2]) % 10007;
    }

    cout << tile[N] << endl;
    return 0;
}