#include <bits/stdc++.h>
using namespace std;
#define rep(i_, s_, t_) for (int i_ = (s_); i_ <= (t_); ++i_)
#define per(i_, s_, t_) for (int i_ = (s_); i_ >= (t_); --i_)

int fa[5005];
long long ans;

struct edge {
    int a, b, c;
    bool operator < (const edge &rhs) const {
        return c < rhs.c;
    }
} p[200005];

int find(int x) {
    while (x != fa[x])
        x = fa[x] = fa[fa[x]];
    return x;
}

int main() {
    int n, m;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    rep (i, 1, m)
        cin >> p[i].a >> p[i].b >> p[i].c;
    sort(p + 1, p + m + 1);
    rep (i, 1, n)
        fa[i] = i;
    int x, y;
    rep (i, 1, m) {
        x = find(p[i].a), y = find(p[i].b);
        if (x != y)
            fa[x] = y, ans += p[i].c;
    }
    int f = find(1);
    rep (i, 1, n)
        if (find(i) != f) {
            cout << "orz" << endl;
            return 0;
        }
    cout << ans << endl;
}