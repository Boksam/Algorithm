#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

__int64_t N, B;
vector<vector<int>> ans;
vector<vector<int>> matrix;


void matrix_mul(vector<vector<int>> &m1, vector<vector<int>> &m2) {
    vector<vector<int>> tmp = vector(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            tmp[i][j] = 0;

            for (int k = 0; k < N; k++)
                tmp[i][j] += m1[i][k] * m2[k][j];
            
            tmp[i][j] %= 1000;
        }
    }
    
    m1 = tmp;
}


int main() {
    cin >> N >> B;

    ans.resize(N, vector<int>(N));
    matrix.resize(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cin >> matrix[i][j];
        ans[i][i] = 1;
    }
        

    while (B > 0) {
        if (B % 2 == 1)
            matrix_mul(ans, matrix);
        matrix_mul(matrix, matrix);
        B /= 2;
    }

    for (auto line : ans) {
        for (auto n : line)
            cout << n << " ";
        cout << '\n';
    }

    return 0;
}