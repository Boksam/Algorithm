#include <iostream>
#include <vector>
using namespace std;

vector<long long> nums = {0,1,1,1,2,2,3,4,5,7,9};
vector<int> Ns;

int main(){
    int N, maxNum = 0, temp;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> temp;
        Ns.push_back(temp);
        if (temp > maxNum)
            maxNum = temp;
    }

    for(int i = 11; i <= maxNum; i++){
        nums.push_back(nums[i-1] + nums[i-5]);
    }
    
    for(int i = 0; i < N; i++){
        cout << nums[Ns[i]] << '\n';
    }
    return 0;
}