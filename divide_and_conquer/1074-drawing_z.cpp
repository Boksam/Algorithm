#include <iostream>
#include <algorithm>
using namespace std;

int N, r, c, answer = 0;


void Z(int y, int x, int size) {
    if (y == r && x == c) {
        cout << answer << '\n';
        return;
    }

    if (!(y <= r && r < y + size) || !(x <= c && c < x + size)) {
        answer += size * size;
        return;
    }

    Z(y, x, size / 2);
    Z(y, x + size / 2, size / 2);
    Z(y + size / 2, x, size / 2);
    Z(y + size / 2, x + size / 2, size / 2);
}


int main() {
    cin >> N >> r >> c;
    int zSize = 1;
    zSize = zSize << N;
    
    Z(0, 0, zSize);
}