#include <bits/stdc++.h>
#define fi first
#define se second
#define SZ(x) int((x).size())
#define endl "\n" 
using namespace std;
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
constexpr int N = 1500 + 10; 
constexpr int INF = 0x3f3f3f3f;
int n;

struct E { 
	int id, l, r; 
	void scan(int _id) { id = _id; rd(l, r); }
	bool operator < (const E &other) const { 
		if (l == other.l)
			return r < other.r; 
		return l < other.l;
	}
}e[N];

int f[N][N], pre[N][N];

void run() {
	rd(n);
	for (int i = 1; i <= n; ++i) e[i].scan(i);
	sort(e + 1, e + 1 + n);
	memset(f, 0x3f, sizeof f);
	memset(pre, -1, sizeof pre); 
	memset(f[0], 0, sizeof f[0]);
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= 1440; ++j) {
			if (f[i - 1][j] != INF) {
				if (f[i - 1][j] <= e[i].l && f[i][j] > e[i].r) {
					f[i][j] = e[i].r;
					pre[i][j] = j; 
				}
				if (j <= e[i].l && f[i][e[i].r] > f[i - 1][j]) {
					f[i][e[i].r] = f[i - 1][j];
					pre[i][e[i].r] = j;
				}
			}
		}
	//	for (int j = 1440 - 1; j >= 0; --j) {
	//		if (f[i][j] > f[i + 1][j]) {
	//			f[i][j] = f[i + 1][j];
	//			pre[i][j] = pre[i + 1][j]; 
	//		}
	//	}
	}	
	for (int i = 0; i <= 1440; ++i) {
		if (f[n][i] != INF) {
			string s(n, ' ');
			int now = i;
			for (int j = n; j >= 1; --j) {
				if (pre[j][now] == now) s[e[j].id - 1] = 'C';
				else s[e[j].id - 1] = 'J';
				now = pre[j][now];
			}
			cout << s << endl;
			return;
		}
	}
	pt("IMPOSSIBLE");
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int _T = nextInt();
    for (int kase = 1; kase <= _T; ++kase) {
        cout << "Case #" << kase << ": ";
        run();
    }
	return 0;
}
