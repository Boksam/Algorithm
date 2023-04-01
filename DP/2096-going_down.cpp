#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> maxDp(3);
    vector<int> minDp(3);
    cin >> maxDp[0] >> maxDp[1] >> maxDp[2];
    minDp = maxDp;

    for (int i = 1; i < N; i++)
    {
        int p1, p2, p3;
        cin >> p1 >> p2 >> p3;

        maxDp = {p1 + max(maxDp[0], maxDp[1]), p2 + max(maxDp[0], max(maxDp[1], maxDp[2])), p3 + max(maxDp[1], maxDp[2])};
        minDp = {p1 + min(minDp[0], minDp[1]), p2 + min(minDp[0], min(minDp[1], minDp[2])), p3 + min(minDp[1], minDp[2])};
    }

    cout << max(maxDp[0], max(maxDp[1], maxDp[2])) << " " << min(minDp[0], min(minDp[1], minDp[2])) << endl;
}