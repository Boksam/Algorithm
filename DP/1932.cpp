#include <iostream>
#include <algorithm>
using namespace std;

int tri[501][501];

int main()
{
    int N;
    cin >> N;

    cin >> tri[0][0];

    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cin >> tri[i][j];

            if (j == 0)
            {
                tri[i][j] += tri[i - 1][j];
            }
            else if (j == i)
            {
                tri[i][j] += tri[i - 1][j - 1];
            }
            else
            {
                tri[i][j] += max(tri[i - 1][j - 1], tri[i - 1][j]);
            }
        }
    }

    int result = 0;
    for (int i = 0; i < N; i++)
    {
        if (result < tri[N - 1][i])
            result = tri[N - 1][i];
    }

    cout << result;
    return 0;
}