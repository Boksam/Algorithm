#include <iostream>
using namespace std;

int arr[10];
bool used[10];
int n, m;


void func(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	else {
		for (int i = 1; i <= n; i++) {
			arr[k] = i;
			used[i] = true;
			func(k + 1);
			used[i] = false;
		}
	}
}

int main() {
	cin >> n >> m;
	func(0);
	return 0;
}