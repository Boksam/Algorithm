#include <iostream>
using namespace std;

int sudoku[10][10];
bool row[10][10];
bool column[10][10];
bool square[10][10];


bool solve(int n) {
	if (n == 81) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << sudoku[i][j] << ' ';
			}
			cout << '\n';
		}
		return true;
	}

	int x = n / 9, y = n % 9;

	if (sudoku[x][y] != 0) {
		return solve(n + 1);
	}
	else {
		for (int i = 1; i <= 9; i++) {
			if (!row[x][i] && !column[y][i] && !square[(x / 3) * 3 + y / 3][i]) {
				row[x][i] = true;
				column[y][i] = true;
				square[(x / 3) * 3 + y / 3][i] = true;
				sudoku[x][y] = i;


				if (solve(n + 1)) {
					return true;
				}

				row[x][i] = false;
				column[y][i] = false;
				square[(x / 3) * 3 + y / 3][i] = false;
				sudoku[x][y] = 0;
			}
		}
	}

	return false;
}

int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> sudoku[i][j];

			if (sudoku[i][j] != 0) {
				row[i][sudoku[i][j]] = true;
				column[j][sudoku[i][j]] = true;
				square[(i / 3) * 3 + j / 3][sudoku[i][j]] = true;
			}
		}
	}

	solve(0);
	return 0;

}