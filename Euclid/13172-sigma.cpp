#include <iostream>
#include <numeric>
using namespace std;

using ll = long long;
const ll MOD = 1000000007;

int M;
ll ans = 0;


ll square(ll a, ll b) {
    if (b == 0) return 1;
    if (b == 1) return a;
    if (b % 2 == 1) return a * square(a, b - 1) % MOD;
    
    ll half = square(a, b / 2);
    return half * half % MOD;
}


int main() {
    cin >> M;
    while (M--) {
        ll N, S;
        cin >> N >> S;
        ans += S * square(N, MOD - 2) % MOD;
        ans %= MOD;
    }

    cout << ans << endl;
    return 0;
}