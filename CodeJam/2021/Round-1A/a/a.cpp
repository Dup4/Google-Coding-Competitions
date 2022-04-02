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
using pII = pair <int, int>;
using pLL = pair <ll, ll>;
constexpr int mod = 1e9 + 7;
template <class T1, class T2> inline void chadd(T1 &x, T2 y, int Mod = mod) { x += y; while (x >= Mod) x -= Mod; while (x < 0) x += Mod; } 
template <class T1, class T2> inline void chmax(T1 &x, T2 y) { if (x < y) x = y; }
template <class T1, class T2> inline void chmin(T1 &x, T2 y) { if (x > y) x = y; }
inline int nextInt() { int x; cin >> x; return x; }
void rd() {}
template <class T, class... Ts> void rd(T& arg, Ts&... args) { cin >> arg; rd(args...); }
#define dbg(x...) do { cout << "\033[32;1m" << #x << " -> "; err(x); } while (0) 
void err() { cout << "\033[39;0m" << endl; } 
template <class T, class... Ts> void err(const T& arg, const Ts&... args) { cout << arg << ' '; err(args...); }
template <template<typename...> class T, typename t, typename... A> 
void err(const T <t> &arg, const A&... args) { for (auto &v : arg) cout << v << ' '; err(args...); }
void ptt() { cout << endl; }
template <class T, class... Ts> void ptt(const T& arg, const Ts&... args) { cout << ' ' << arg; ptt(args...); }
template <class T, class... Ts> void pt(const T& arg, const Ts&... args) { cout << arg; ptt(args...); }
void pt() {}
template <template<typename...> class T, typename t, typename... A>
void pt(const T <t> &arg, const A&... args) { for (int i = 0, sze = arg.size(); i < sze; ++i) cout << arg[i] << " \n"[i == sze - 1]; pt(args...); }
inline ll qpow(ll base, ll n) { assert(n >= 0); ll res = 1; while (n) { if (n & 1) res = res * base % mod; base = base * base % mod; n >>= 1; } return res; }
//head
constexpr int N = 1e2 + 10; 
int n;
string s[N];

int comp(const string &A, const string &B) {
    if (A.length() > B.length()) return 1;
    if (A.length() < B.length()) return -1;
    int len = A.length();
    for (int i = 0; i < len; ++i) {
        if (A[i] > B[i]) return 1;
        if (A[i] < B[i]) return -1;
    }
    return 0;
}

void run() {
    n = nextInt();
    for (int i = 1; i <= n; ++i) rd(s[i]);
    int res = 0;
    for (int i = 2; i <= n; ++i) {
        int _comp = comp(s[i], s[i - 1]);
        if (_comp == 1) continue;
        if (s[i].length() == s[i - 1].length()) {
            s[i] += "0";
            ++res;
        } else {
            int comp = 0;
            for (int j = 0; j < (int)s[i].length(); ++j) {
                if (s[i][j] > s[i - 1][j]) {
                    comp = 1;
                    break;
                }
                if (s[i][j] < s[i - 1][j]) {
                    comp = -1;
                    break;
                }
            }
            bool all9 = true;
            for (int j = (int)s[i].length(); j < (int)s[i - 1].length(); ++j) {
                if (s[i - 1][j] != '9') {
                    all9 = false;
                    break;
                }
            }
            if (all9 && comp == 0) comp = -1;
            if (comp == 1) {
                int need = s[i - 1].length() - s[i].length();
             //   dbg(i, need, string(need, '0'));
                s[i] += string(need, '0');
                res += need;
            } else if (comp == -1) {
                int need = s[i - 1].length() - s[i].length() + 1;
                s[i] += string(need, '0');
                res += need;
            } else {
                int need = s[i - 1].length() - s[i].length();
                res += need;
                for (int j = (int)s[i].length(); j < (int)s[i - 1].length(); ++j) {
                    s[i] += s[i - 1][j];
                }
                for (int j = (int)s[i].length() - 1; j >= 0; --j) {
                    if (s[i][j] == '9') s[i][j] = '0';
                    else {
                        ++s[i][j];
                        break;
                    }
                }
            }
        }
    }
  //  for (int i = 1; i <= n; ++i) dbg(s[i]);
    pt(res);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
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
