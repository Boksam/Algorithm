#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> nums;
vector<bool> used;
vector<int> ans;

void back_tracking(int idx) {
    if (idx == M) {
        for (int num : ans)
            cout << num << " ";
        cout << '\n';
        return;
    }

    for (int i = 0; i < N; i++) {
        if (!used[i]) {
            used[i] = true;
            ans.push_back(nums[i]); 

            back_tracking(idx + 1);

            used[i] = false;
            ans.pop_back();
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> M;

    used.resize(N);
    nums.resize(N);

    for (int i = 0; i < N; i++)
        cin >> nums[i];
    
    sort(nums.begin(), nums.end());

    back_tracking(0);
}