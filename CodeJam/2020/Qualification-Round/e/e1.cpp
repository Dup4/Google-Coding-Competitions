#include <bits/stdc++.h>
#define fi first
#define se second
#define SZ(x) int((x).size())
#define endl "\n"
using namespace std;
using db = double;
using ll = long long;
using ull = unsigned long long;
using pII = pair<int, int>;
using pLL = pair<ll, ll>;
constexpr int mod = 1e9 + 7;
template <class T1, class T2>
inline void chadd(T1 &x, T2 y, int Mod = mod) {
    x += y;
    while (x >= Mod) x -= Mod;
    while (x < 0) x += Mod;
}
template <class T1, class T2>
inline void chmax(T1 &x, T2 y) {
    if (x < y)
        x = y;
}
template <class T1, class T2>
inline void chmin(T1 &x, T2 y) {
    if (x > y)
        x = y;
}
inline int nextInt() {
    int x;
    cin >> x;
    return x;
}
void rd() {}
template <class T, class... Ts>
void rd(T &arg, Ts &...args) {
    cin >> arg;
    rd(args...);
}
#define dbg(x...)                             \
    do {                                      \
        cout << "\033[32;1m" << #x << " -> "; \
        err(x);                               \
    } while (0)
void err() {
    cout << "\033[39;0m" << endl;
}
template <class T, class... Ts>
void err(const T &arg, const Ts &...args) {
    cout << arg << ' ';
    err(args...);
}
template <template <typename...> class T, typename t, typename... A>
void err(const T<t> &arg, const A &...args) {
    for (auto &v : arg) cout << v << ' ';
    err(args...);
}
void ptt() {
    cout << endl;
}
template <class T, class... Ts>
void ptt(const T &arg, const Ts &...args) {
    cout << ' ' << arg;
    ptt(args...);
}
template <class T, class... Ts>
void pt(const T &arg, const Ts &...args) {
    cout << arg;
    ptt(args...);
}
void pt() {}
template <template <typename...> class T, typename t, typename... A>
void pt(const T<t> &arg, const A &...args) {
    for (int i = 0, sze = arg.size(); i < sze; ++i) cout << arg[i] << " \n"[i == sze - 1];
    pt(args...);
}
inline ll qpow(ll base, ll n) {
    assert(n >= 0);
    ll res = 1;
    while (n) {
        if (n & 1)
            res = res * base % mod;
        base = base * base % mod;
        n >>= 1;
    }
    return res;
}
// head
constexpr int N = 1e2 + 10;
int n, K;
vector<vector<int>> a;
vector<vector<int>> Per;
map<int, int> mp;

void dfs(int cur) {
    if (cur < n - 1) {
        for (auto &it : Per) {
            a[cur] = it;
            dfs(cur + 1);
        }
    } else {
        a[cur].resize(n);
        for (int i = 0; i < n; ++i) {
            mp.clear();
            for (int j = 0; j < n - 1; ++j) {
                if (mp[a[j][i]])
                    return;
                mp[a[j][i]] = 1;
            }
            int pos = 0;
            for (auto &it : mp) {
                if (it.fi == pos)
                    ++pos;
                else
                    break;
            }
            a[n - 1][i] = pos;
        }
        mp.clear();
        for (int i = 0; i < n; ++i) {
            if (mp[a[n - 1][i]])
                return;
            mp[a[n - 1][i]] = 1;
        }
        int tot = 0;
        for (int i = 0; i < n; ++i) {
            tot += a[i][i] + 1;
        }
        if (tot == K) {
            cout << "{";
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) cout << a[i][j] + 1 << ", "[i == n - 1 && j == n - 1];
            }
            cout << "},";
            throw 1;
        }
    }
}

void run() {
    vector<int> staPer;
    for (int i = 0; i < n; ++i) staPer.push_back(i);
    Per.clear();
    do {
        Per.push_back(staPer);
    } while (next_permutation(staPer.begin(), staPer.end()));
    a.clear();
    a.resize(n);
    try {
        dfs(0);
    } catch (int e) {
        return;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(20);
    n = 5;
    for (int i = 5; i <= 25; ++i) {
        K = i;
        run();
    }
    return 0;
}
