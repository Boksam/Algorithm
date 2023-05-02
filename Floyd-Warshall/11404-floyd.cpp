#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;

int n, m;
vector<vector<int>> table;

void floyd_warshall()
{
    for (int i = 1; i < n + 1; i++)
    {
        table[i][i] = 0;
    }

    for (int k = 1; k < n + 1; k++)
        for (int i = 1; i < n + 1; i++)
            for (int j = 1; j < n + 1; j++)
                if (table[i][j] > table[i][k] + table[k][j]) {
                    table[i][j] = table[i][k] + table[k][j];
                }

    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < n + 1; j++)
            if (table[i][j] == INF)
                table[i][j] = 0;

}

int main()
{
    cin >> n >> m;

    table.resize(n + 1, vector<int>(n + 1, INF));

    for (int i = 0; i < m; i++)
    {
        int s, e, c;
        cin >> s >> e >> c;
        table[s][e] = min(table[s][e], c);
    }

    floyd_warshall();

    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            cout << table[i][j] << " ";
        }
        cout << '\n';
    }
}