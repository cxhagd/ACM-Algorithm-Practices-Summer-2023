#include<iostream>
#include<algorithm>
using namespace std;
int n, s;
int a, b;
struct ap {
	int x;
	int y;
};
bool cmp(ap m, ap n) {
	return m.y < n.y;
}
ap app[5101];
int main() {
	cin >> n >> s;
	cin >> a >> b;
	for (int i = 1; i <= n; i++) {
		cin >> app[i].x >> app[i].y;
	}
	sort(&app[1], &app[n + 1], cmp);
	int ans = 0;
	for (int i = 1; i <= n&&s >= 0; i++) {
		if (a + b >= app[i].x && s - app[i].y >= 0) {
			s -= app[i].y;
			ans++;
		}
	}
	cout << ans;
}