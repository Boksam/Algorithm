#include <iostream>
using namespace std;

int arr[10];
bool used[10];
int n, m;


void func(int k, int pos) {
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	else {
		for (int i = pos; i <= n; i++) {
			arr[k] = i;
			used[i] = true;
			func(k + 1, i);
			used[i] = false;
		}
	}
}

int main() {
	cin >> n >> m;
	func(0, 1);
	return 0;
}