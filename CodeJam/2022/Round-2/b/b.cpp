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

template <typename T, typename S>
inline bool chmax(T &a, const S &b) {
    return a < b ? a = b, 1 : 0;
}

template <typename T, typename S>
inline bool chmin(T &a, const S &b) {
    return a > b ? a = b, 1 : 0;
}

// head
const int N = 1e4 + 10;
int r;
int f[N][N];

int get_pixel(int x, int y) {
    return f[x + 100][y + 100];
}

void set_pixel(int x, int y, int v = 0) {
    f[x + 100][y + 100] = v;
}

void set_pixel_to_black(int x, int y) {
    set_pixel(x, y, 1);
}

int get_all_pixel() {
    int res = 0;

    for (int i = -r; i <= r; i++) {
        for (int j = -r; j <= r; j++) {
            res += get_pixel(i, j);
        }
    }

    return res;
}

void init() {
    for (int i = -r; i <= r; i++) {
        for (int j = -r; j <= r; j++) {
            set_pixel(i, j, 0);
        }
    }
}

void draw_circle_perimeter(int r) {
    for (int x = -r; x <= r; x++) {
        int y = static_cast<int>(round(sqrt(r * r - x * x)));

        set_pixel_to_black(x, y);
        set_pixel_to_black(x, -y);
        set_pixel_to_black(y, x);
        set_pixel_to_black(-y, x);
    }
}

void draw_circle_filled_wrong(int r) {
    for (int i = 0; i <= r; i++) {
        draw_circle_perimeter(i);
    }
}

void draw_circle_filled(int r) {
    for (int i = -r; i <= r; i++) {
        for (int j = -r; j <= r; j++) {
            int x = static_cast<int>(round(sqrt(i * i + j * j)));
            if (x <= r) {
                set_pixel_to_black(i, j);
            }
        }
    }
}

void run() {
    cin >> r;

    init();
    draw_circle_filled(r);
    int a = get_all_pixel();

    init();
    draw_circle_filled_wrong(r);
    int b = get_all_pixel();

    cout << abs(a - b) << endl;
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
