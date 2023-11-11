#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector <long long> nums = {0,1,2};
    for (int i = 3; i <= N; i++){
        nums.push_back((nums[i-1]+nums[i-2]) % 15746);
    }
    cout << nums[N] % 15746;
    return 0;
}