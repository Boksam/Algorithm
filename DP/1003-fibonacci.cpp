#include <iostream>
using namespace std;

int count_0 = 0, count_1 = 0;

int fibonacci(int num){
    if (num == 0){
        count_0++;
        return 0;
    }
    if (num == 1){
        count_1++;
        return 1;
    }

    return fibonacci(num-1) + fibonacci(num-2);
}

int main(){
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++){
        count_0 = 0;
        count_1 = 0;

        int test_num;
        cin >> test_num;

        fibonacci(test_num);

        cout << count_0 << " " << count_1 << '\n';
    }
}