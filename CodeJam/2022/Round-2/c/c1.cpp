#include <bits/stdc++.h>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <limits>
#include <utility>

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

int n;

long long calcDis(int x, int y, int nx, int ny) {
    return 1ll * (x - nx) * (x - nx) + 1ll * (y - ny) * (y - ny);
}

ll dis[30][30];

struct node {
    int ix;
    long long dis;

    bool operator<(const node &other) const {
        return dis < other.dis;
    }
};

void run() {
    cin >> n;

    vector<pair<int, int>> f, g;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        f.push_back(make_pair(x, y));
    }

    for (int i = 0; i < n + 1; i++) {
        int x, y;
        cin >> x >> y;
        g.push_back(make_pair(x, y));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + 1; j++) {
            dis[i][j] = calcDis(f[i].first, f[i].second, g[j].first, g[j].second);
        }
    }

    vector<int> h;
    h.reserve(n);
    for (int i = 0; i < n; i++) {
        h.push_back(i);
    }

    do {
        vector<pair<int, int>> res;
        vector<int> vis(n + 1, 0);
        int all_ok = 1;

        for (int i = 0; i < n; i++) {
            vector<node> tmp;

            int ix = h[i];
            int x = f[ix].first, y = f[ix].second;

            for (int j = 0; j < n + 1; j++) {
                if (vis[j] == 0) {
                    int nx = g[j].first, ny = g[j].second;
                    ll curDis = calcDis(x, y, nx, ny);

                    tmp.emplace_back(node{
                            .ix = j,
                            .dis = curDis,
                    });
                }
            }

            sort(tmp.begin(), tmp.end());

            while (tmp.size() > 1 && tmp.back().dis > tmp[0].dis) {
                tmp.pop_back();
            }

            int ok = 0;
            for (const auto &c : tmp) {
                if (c.ix != 0) {
                    res.push_back(make_pair(ix + 1, c.ix + 1));
                    ok = 1;
                    vis[c.ix] = 1;
                    break;
                }
            }

            if (ok == 0) {
                all_ok = 0;
                break;
            }
        }

        if (all_ok) {
            cout << "POSSIBLE\n";

            for (const auto &r : res) {
                cout << r.first << " " << r.second << "\n";
            }

            return;
        }
    } while (next_permutation(h.begin(), h.end()));

    cout << "IMPOSSIBLE\n";
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
