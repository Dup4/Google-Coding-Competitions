#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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

// #ifdef LOCAL
// #include <debug.hpp>
// #else
// #define dbg(...)
// #endif
// head
const int N = 1e4 + 10;
int n, k;
int f[N][N];

int mv[][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void genG() {
    int ix = 1;
    int mx = 0;
    int x = 1, y = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            f[i][j] = -1;
        }
    }

    const auto ok = [](int x, int y) {
        if (x < 1 || x > n || y < 1 || y > n) {
            return false;
        }

        if (f[x][y] != -1) {
            return false;
        }

        return true;
    };

    f[1][1] = 1;

    while (ix < n * n) {
        ++ix;
        int nx = x + mv[mx][0];
        int ny = y + mv[mx][1];

        if (!ok(nx, ny)) {
            mx = (mx + 1) % 4;
        }

        nx = x + mv[mx][0];
        ny = y + mv[mx][1];

        x = nx;
        y = ny;

        f[x][y] = ix;
    }
}

void printG() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << f[i][j] << " \n"[j == n];
        }
    }
}

struct node {
    int x, y, v;
    bool operator<(const node &other) const {
        return v > other.v;
    }
};

vector<pair<int, int>> gao() {
    auto res = vector<pair<int, int>>();

    const auto ok = [](int x, int y) {
        if (x < 1 || x > n || y < 1 || y > n) {
            return false;
        }

        return true;
    };

    node cur = {
            .x = 1,
            .y = 1,
            .v = 1,
    };

    int _k = k;
    int target = n * n;
    while (_k > 0) {
        vector<node> t;

        // cout << cur.x << " " << cur.y << " " << cur.v << " " << _k << " " << res.size() << endl;

        for (int i = 0; i < 4; i++) {
            int nx = cur.x + mv[i][0];
            int ny = cur.y + mv[i][1];
            if (ok(nx, ny) && f[nx][ny] > cur.v) {
                t.emplace_back(node{
                        .x = nx,
                        .y = ny,
                        .v = f[nx][ny],
                });
            }
        }

        sort(t.begin(), t.end());

        int ok = 0;

        for (const auto &nx : t) {
            if (_k - 1 <= target - nx.v) {
                if (nx.v - cur.v > 1) {
                    res.push_back(make_pair(cur.v, nx.v));
                }

                cur = nx;
                ok = 1;

                break;
            }
        }

        if (ok == 0) {
            return vector<pair<int, int>>();
        }

        --_k;
    }

    if (cur.v != target) {
        return vector<pair<int, int>>();
    }

    return res;
}

void run() {
    cin >> n >> k;
    genG();
    // printG();

    auto res = gao();

    if (res.empty()) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << res.size() << "\n";
        for (const auto &it : res) {
            cout << it.first << " " << it.second << "\n";
        }
    }
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
