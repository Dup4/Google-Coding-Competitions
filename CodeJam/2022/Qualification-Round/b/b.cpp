#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define endl "\n"
#define fi first
#define se second
#define all(x) begin(x), end(x)
#define rall rbegin(a), rend(a)
#define bitcnt(x) (__builtin_popcountll(x))
#define complete_unique(a) a.erase(unique(begin(a), end(a)), end(a))
#define mst(x, a) memset(x, a, sizeof(x))
#define MP make_pair

using ll = long long;
using ull = unsigned long long;
using db = double;
using ld = long double;
using VLL = std::vector<ll>;
using VI = std::vector<int>;
using PII = std::pair<int, int>;
using PLL = std::pair<ll, ll>;

using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const ll mod = 1e9 + 7;

template <typename T, typename S>
inline bool chmax(T &a, const S &b) {
    return a < b ? a = b, 1 : 0;
}

template <typename T, typename S>
inline bool chmin(T &a, const S &b) {
    return a > b ? a = b, 1 : 0;
}

#ifdef LOCAL
#include <debug.hpp>
#else
#define dbg(...)
#endif
// head

void run() {
    constexpr int Max = 1000000;
    auto vec = vector<vector<int>>(4, vector<int>(3, 0));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            int x;
            cin >> x;
            vec[j][i] = x;
        }
    }

    auto res = vector<int>();
    for (int i = 0; i < 4; i++) {
        res.push_back(*min_element(all(vec[i])));
    }

    int tot = accumulate(all(res), 0);

    if (tot < Max) {
        cout << "IMPOSSIBLE\n";
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (tot > Max) {
            if (res[i] <= tot - Max) {
                tot -= res[i];
                res[i] = 0;
            } else {
                res[i] -= tot - Max;
                tot = Max;
            }
        }

        cout << res[i] << " \n"[i == 3];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(20);

    int _T;
    cin >> _T;
    for (int i = 1; i <= _T; ++i) {
        cout << "Case #" << i << ": ";
        run();
    }

    return 0;
}
