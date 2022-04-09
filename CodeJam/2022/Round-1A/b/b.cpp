#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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
    int n;
    cin >> n;

    vector<int> f;
    for (int i = 0; i < 30; i++) {
        f.push_back(1 << i);
    }

    int ix = 1000000001;
    while (f.size() < n) {
        --ix;
        if ((ix & (ix - 1)) == 0) {
            continue;
        }

        f.push_back(ix);
    }

    for (int i = 0; i < n; i++) {
        cout << f[i];
        if (i == n - 1) {
            cout << endl;
        } else {
            cout << " ";
        }
    }

    cout << flush;

    ll sum = accumulate(all(f), 0ll);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        f.push_back(x);
        sum += x;
    }

    assert(sum % 2 == 0);
    ll tar = sum / 2;

    sort(all(f), greater<int>());

    auto res = vector<int>();

    for (const auto &a : f) {
        if ((a & (a - 1)) == 0) {
            continue;
        }

        if (tar < (1 << 30)) {
            break;
        }

        tar -= a;
        res.push_back(a);
    }

    for (int i = 0; i < 30; i++) {
        if ((tar >> i) & 1) {
            res.push_back(1 << i);
        }
    }

    for (int i = 0; i < res.size(); i++) {
        cout << res[i];
        if (i == res.size() - 1) {
            cout << endl;
        } else {
            cout << " ";
        }
    }

    cout << flush;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(20);

    int _T;
    cin >> _T;
    for (int i = 1; i <= _T; ++i) {
        run();
    }

    return 0;
}
