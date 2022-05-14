#include <bits/stdc++.h>
#include <algorithm>
#include <cstring>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <limits>
#include <utility>
#include <vector>

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

template <typename T, typename S>
inline bool chmax(T &a, const S &b) {
    return a < b ? a = b, 1 : 0;
}

template <typename T, typename S>
inline bool chmin(T &a, const S &b) {
    return a > b ? a = b, 1 : 0;
}

// head
const int N = 1e5 + 10;
int n, C;

struct node {
    int x;
    int v;

    bool operator<(const node &other) const {
        return x < other.x;
    }
};

ll gao(vector<node> &v) {
    int m = v.size();

    v.emplace_back(node{
            .x = -1,
            .v = 0,
    });

    sort(v.begin(), v.end());

    vector<vector<ll>> f(m + 1, vector<ll>(3, 1ll * 10000 * 1e9));

    f[0][2] = 0;

    for (int i = 1; i <= m; i++) {
        ll baseCost = 1ll * v[i].x * 2;

        for (int j = 0; j <= 2; j++) {
            f[i][j] = min(f[i][j], f[i - 1][j] + baseCost);
        }

        f[i][v[i].v] = min(f[i][v[i].v], f[i - 1][2]);

        f[i][2] = min(f[i][2], f[i - 1][v[i].v ^ 1] + baseCost);
        f[i][2] = min(f[i][2], f[i - 1][v[i].v] + baseCost + C);
    }

    return f[m][2];
}

void run() {
    cin >> n >> C;

    vector<node> f, g;
    for (int i = 0; i < n; i++) {
        int x, v;
        cin >> x >> v;

        if (x < 0) {
            f.push_back(node{
                    .x = -x,
                    .v = v,
            });
        } else {
            g.push_back(node{
                    .x = x,
                    .v = v,
            });
        }
    }

    ll ans = 0;
    ans += gao(f);
    ans += gao(g);

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(20);

    int _T = 0;
    cin >> _T;
    for (int i = 1; i <= _T; ++i) {
        cout << "Case #" << i << ": ";
        run();
    }

    return 0;
}
