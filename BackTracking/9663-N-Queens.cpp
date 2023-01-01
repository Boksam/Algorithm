#include <iostream>
using namespace std;

int result = 0;
bool column[40] = { false, }, diagnalRight[40] = { false, }, diagnalLeft[40] = { false, };

void nQueens(int n, int k = 0) {
	if (k == n) {
		result++;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (column[i] || diagnalRight[i - k + n - 1] || diagnalLeft[i + k]) {
			continue;
		}
		else {
			column[i] = true;
			diagnalRight[i - k + n - 1] = true;
			diagnalLeft[i + k] = true;
			nQueens(n, k + 1);
			column[i] = false;
			diagnalRight[i - k + n - 1] = false;
			diagnalLeft[i + k] = false;
		}
	}
}


int main() {
	int N;
	cin >> N;
	nQueens(N, 0);
	cout << result;
	return 0;
}