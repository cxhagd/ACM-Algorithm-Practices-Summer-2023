#include<iostream>
#include<algorithm>
using namespace std;
int n;
struct stick {
	int len;
	int wid;
};
stick wood[5111];
bool cmp(stick a, stick b)
{
	if (a.len != b.len) {
		return a.len > b.len;
	}
	else {
		return a.wid > b.wid;
	}
}
int ans = 0;
int f[5111];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> wood[i].len >> wood[i].wid;
	}

	sort(&wood[1], &wood[n + 1], cmp);

	for (int i = 1; i <= n; i++) {
		if (wood[i].wid > f[ans]) {
			f[++ans] = wood[i].wid;
		}
		else {
			int tmp = lower_bound(&f[1], &f[ans + 1],wood[i].wid) - f;
			f[tmp] = wood[i].wid;
		}

	}

	cout << ans << endl;

}