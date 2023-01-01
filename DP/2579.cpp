#include <iostream>
#include <algorithm>
using namespace std;

int stairs[301];
int points[301];

int main()
{
    int N;
    cin >> N;
    stairs[0] = 0;
    for (int i = 1; i <= N; i++)
    {
        cin >> stairs[i];
    }
    points[0] = 0;
    points[1] = stairs[1];
    points[2] = stairs[1] + stairs[2];
    points[3] = max(stairs[1], stairs[2]) + stairs[3];

    for (int i = 4; i <= N; i++)
    {
        points[i] = max(points[i - 2] + stairs[i], points[i - 3] + stairs[i - 1] + stairs[i]);
    }

    cout << points[N];
    return 0;
}