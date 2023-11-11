#include <iostream>
#include <vector>
using namespace std;
/*
	1 = µ¡¼À, 2 = »¬¼À, 3 = °ö¼À, 4 = ³ª´°¼À

*/
vector<bool> checkCal;
vector<int> cal;
vector<int> nums;
vector<int> selectCal;
int maxNum = -1000000000, minNum = 1000000000;

void solve(int n) {
	if (n == cal.size()) {
		int result = nums[0];
		for (int i = 1; i < nums.size(); i++) {
			switch (selectCal[i - 1]) {
			case 1:
				result += nums[i];
				break;
			case 2:
				result -= nums[i];
				break;
			case 3:
				result *= nums[i];
				break;
			case 4:
				result /= nums[i];
				break;
			default:
				break;
			}
		}
		if (maxNum < result)
			maxNum = result;
		if (minNum > result)
			minNum = result;
		return;
	}

	for (int i = 0; i < cal.size(); i++) {
		if (!checkCal[i]) {
			selectCal.push_back(cal[i]);
			checkCal[i] = true;
			solve(n + 1);
			selectCal.pop_back();
			checkCal[i] = false;
		}
	}
}


int main() {
	int N, tempCal;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		nums.push_back(temp);
	}
	for (int i = 1; i < 5; i++) {
		cin >> tempCal;
		for (int j = 0; j < tempCal; j++) {
			checkCal.push_back(false);
			cal.push_back(i);
		}
	}
	solve(0);
	cout << maxNum << '\n' << minNum;

	return 0;
}