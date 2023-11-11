#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n, r, c, cnt = 0;

void divide_and_conquer(int y, int x, int size) {
  if (y == r && x == c) {
    cout << cnt << endl;
    return;
  }

  if (!(y <= r && r < y + size) || !(x <= c && c < x + size)) {
    cnt += size * size;
    return;
  }

  divide_and_conquer(y, x, size / 2);
  divide_and_conquer(y, x + size / 2, size / 2);
  divide_and_conquer(y + size / 2, x, size / 2);
  divide_and_conquer(y + size / 2, x + size / 2, size / 2);
}

int main() {
  cin >> n >> r >> c;
  n = 1 << n;

  divide_and_conquer(0, 0, n);
  return 0;
}