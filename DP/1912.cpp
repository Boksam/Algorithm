#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
using namespace std;

vector<int> nums;
vector<int> dp;

int main()
{
    int N, temp;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        nums.push_back(temp);
    }

    dp.push_back(nums[0]);
    int result = nums[0];
    for (int i = 1; i < N; i++)
    {
        dp.push_back(max(dp[i - 1] + nums[i], nums[i]));
        result = max(dp[i], result);
    }
    cout << result;
    return 0;
}