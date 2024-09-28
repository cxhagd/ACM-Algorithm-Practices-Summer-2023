#include<iostream>
using namespace std;
int N, M, Q;
int tt[211];
int f[211][211];
inline void updata(int  k) {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (f[i][j] > f[i][k] + f[j][k]) {
				f[i][j] = f[i][k] + f[j][k];
				f[j][i] = f[i][k] + f[j][k];
			}
		}
	}
}
int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> tt[i];
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			f[i][j] = 1e9;
		}
	}
	for (int k = 1; k <= M; k++) {
		int i, j, w;
		cin >> i >> j >> w;
		i++; j++;
		f[i][j] = w;
		f[j][i] = w;
	}
	cin >> Q;
	int x, y, t, now = 1;
	for (int q = 1; q <= Q; q++) {
		cin >> x >> y >> t;
		x++; y++;
		while (tt[now] <= t && now <= N) {
			updata(now);
			now++;
		}
		if (tt[x] > t || tt[y] > t) {
			cout << "-1" << endl;
		}
		else {
			if (f[x][y] == 1e9) {
				cout << "-1" << endl;
			}
			else {
				cout << f[x][y] << endl;
			}
		}

	}


}