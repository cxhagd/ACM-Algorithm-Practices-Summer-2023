#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
struct edge {
	int beg, end;double len;
};
int x[600], y[600];
edge e[300000];
int s, p, n,d;//n是边的数量 d是点的数量 
int fa[600];
int k;double ans;
int find(int x) {
	if (fa[x] != x) {
		fa[x] = find(fa[x]);
	}
	return fa[x];
}
void unity(int x, int y) {
	fa[find(x)] = find(y);
}

bool cmp(edge a, edge b) {
	return a.len < b.len;
}
int main() {
	cin >> s >> p;
	for (int i = 1; i <= p; i++) {
		cin >> x[i] >> y[i];
		d = i;
		for (int j = 1; j < i; j++) {
			n++;
			e[n].beg = i;
			e[n].end = j;
			e[n].len = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
		}
	}

	for (int i = 1; i <= d; i++) {
		fa[i] = i;
	}
	sort(&e[1], &e[n + 1], cmp);

	for (int i = 1; i <= n; i++) {
		if (find(e[i].beg) != find(e[i].end)) {
			unity(e[i].beg, e[i].end);
			ans = e[i].len;
			k++;
			if (k == p - s) {
				printf("%.2lf\n",ans);
				return 0;
			}
		}
	}


}