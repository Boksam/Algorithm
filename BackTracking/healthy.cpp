#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int k;
int min_cost = 1e9, curr_cost = 0;
int max_neut_sum = -1e9, curr_neut_sum = 0;
vector<vector<int>> ingredient;
vector<int> cost;
vector<int> curr_neut(4);
vector<int> remain_neut(4);
vector<int> min_neut(4);
vector<int> final_ans;
vector<int> curr_ans; // idx 저장


void back_tracking(int n) {
    if (curr_cost > min_cost)
        return;

    for (int i = 0; i < 4; i++)
        if (curr_neut[i] + remain_neut[i] < min_neut[i]) return;

    if (n == k) {
        if (curr_neut[0] >= min_neut[0] && curr_neut[1] >= min_neut[1]
        && curr_neut[2] >= min_neut[2] && curr_neut[3] >= min_neut[3]) {
            if (curr_cost < min_cost) {
                min_cost = curr_cost;
                final_ans = curr_ans;
                max_neut_sum = curr_neut_sum;
            }
            else if (curr_cost == min_cost && curr_neut_sum > max_neut_sum) {
                min_cost = curr_cost;
                final_ans = curr_ans;
                max_neut_sum = curr_neut_sum;
            }
        }
        return;
    }
    
    for (int i = 0; i < 4; i++) {
        curr_neut[i] += ingredient[n][i];
        remain_neut[i] -= ingredient[n][i];
        curr_neut_sum += ingredient[n][i];
    }
    curr_cost += cost[n];
    curr_ans.push_back(n);

    back_tracking(n + 1);   // 선택함
    
    for (int i = 0; i < 4; i++) {
        curr_neut[i] -= ingredient[n][i];
        curr_neut_sum -= ingredient[n][i];
    }
    curr_cost -= cost[n];
    curr_ans.pop_back();

    back_tracking(n + 1);   // 선택 안함

    for (int i = 0; i < 4; i++)
        remain_neut[i] += ingredient[n][i];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> k;
    ingredient.resize(k, vector<int>(4));
    cost.resize(k);

    for (int i = 0; i < 4; i++)
        cin >> min_neut[i];

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> ingredient[i][j];
            remain_neut[j] += ingredient[i][j];
        }
        cin >> cost[i];
    }

    back_tracking(0);

    if (final_ans.size() == 0) {        // 정답 출력
        cout << "0\n";
    }
    else{
        for (auto idx : final_ans)
            cout << idx + 1 << " ";
        cout << '\n';
    }
    return 0;
}