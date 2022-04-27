#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define mkp make_pair
#define all(x) (x).begin(), (x).end()
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
constexpr int N = 1e5 + 10;
int n, q;

struct node {
    string s;
    int score;
    node() {}
    void input() {
        rd(s, score);
    }
} a[N];

int calc(const string &A, const string &B) {
    int score = 0;
    for (int i = 0; i < (int)A.length(); ++i) {
        if (A[i] == B[i])
            ++score;
    }
    return score;
}

void run() {
    rd(n, q);
    for (int i = 1; i <= n; ++i) a[i].input();
    vector<string> mbcn;
    for (int i = 0; i < (1 << q); ++i) {
        string s = "";
        for (int j = 0; j < q; ++j) {
            if ((i >> j) & 1)
                s += "T";
            else
                s += "F";
        }
        bool ok = true;
        for (int j = 1; j <= n; ++j) {
            if (calc(a[j].s, s) != a[j].score) {
                ok = false;
                break;
            }
        }
        if (ok)
            mbcn.push_back(s);
    }
    //  for (auto &it : mbcn) cout << it << endl;
    string ans = string(q, 'T');
    int score = 0;
    for (int i = 0; i < (1 << q); ++i) {
        string s = "";
        for (int j = 0; j < q; ++j) {
            if ((i >> j) & 1)
                s += "T";
            else
                s += "F";
        }
        int _score = 0;
        for (auto &it : mbcn) {
            _score += calc(s, it);
        }
        if (_score > score) {
            score = _score;
            ans = s;
        }
    }
    int k = (int)mbcn.size();
    int g = __gcd(score, k);
    score /= g;
    k /= g;
    cout << ans << " " << score << "/" << k << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(20);
    int _T = nextInt();
    //	while (_T--) run();
    for (int kase = 1; kase <= _T; ++kase) {
        cout << "Case #" << kase << ": ";
        run();
    }
    //	while (cin >> n) run();
    //	run();
    return 0;
}
