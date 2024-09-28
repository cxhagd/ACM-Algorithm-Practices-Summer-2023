#include<iostream>
using namespace std;
int n;
char c[201][201];
int sum[201][201];
int ans = 0;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int len=0;
		for (int j = 1; j <= n; j++) {
			cin >> c[i][j];
		
			if (c[i][j] == 'B') {
				len++;
			}
			sum[i][j] += sum[i - 1][j] + len;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int x = n - j; x >= 0; x--) {
				for (int y = 0; y <= i - 1; y++) {
					if (!(sum[j + x][i] - sum[j - 1][i] - sum[j + x][i - y - 1] + sum[j - 1][i - y - 1])) {
						ans++;
					}
				}
			}
		}
	}
	cout << ans;







}