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

const int INF = 0x3f3f3f3f;

// int sol1(int E, int W, vector<vector<int>> &vec) {
//     int pre = 0;
//     vec.push_back({0, 0});

//     int res = 0;

//     for (int i = 1; i <= E + 1; i++) {
//         res += abs(pre - vec[i][1]);
//         pre = vec[i][1];
//     }

//     return res;
// }

struct node {
    vector<int> a;
    int v;
    int calc(const node &pre) {
        int i = 0;
        while (i < a.size() && i < pre.a.size()) {
            if (a[i] != pre.a[i]) {
                break;
            }

            ++i;
        }

        return pre.a.size() - i + a.size() - i;
    }

    bool operator<(const node &other) const {
        return v < other.v;
    }
};

void run() {
    int E, W;
    cin >> E >> W;
    auto vec = vector<vector<int>>(E + 1, vector<int>(W + 1, 0));
    for (int i = 1; i <= E; i++) {
        for (int j = 1; j <= W; j++) {
            int x;
            cin >> x;
            vec[i][j] = x;
        }
    }

    // if (W == 1) {
    //     cout << sol1(E, W, vec) << endl;
    //     return;
    // }

    auto f = vector<vector<node>>(E + 1, vector<node>());
    f[0].push_back(node{.a = {}, .v = 0});

    for (int i = 1; i <= E; i++) {
        auto t = vector<int>();
        for (int j = 1; j <= W; j++) {
            int cnt = vec[i][j];
            if (cnt == 0) {
                continue;
            }

            auto tt = vector<int>(cnt, j);
            t.insert(t.end(), all(tt));
        }

        // for (int o = 0; o < t.size(); o++) {
        //     cout << t[o] << " ";
        // }
        // cout << endl;

        do {
            auto now = node();
            now.a = t;
            now.v = INF;
            for (const auto &_f : f[i - 1]) {
                now.v = min(now.v, _f.v + now.calc(_f));
            }
            f[i].push_back(now);
        } while (next_permutation(all(t)));
    }

    int res = INF;
    for (const auto &_f : f[E]) {
        res = min(res, int(_f.v + _f.a.size()));
    }

    cout << res << endl;
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
