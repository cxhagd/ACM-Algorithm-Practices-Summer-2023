#include<iostream>
#include<algorithm>
using namespace std;
int a[5010][5001] = {0};
int sa[5010];


int main() {
	int n;
	cin >> n;
	
	a[1][1] = 1;
	sa[1] =1;
	a[2][1] = 2;
	sa[2] =1;
	for (int i = 3; i <= n; i++) {
		sa[i] = max(sa[i - 1], sa[i - 2]) + 1;
		for (int j = 1; j <= sa[i]; j++) {
			a[i][j] += a[i - 1][j] + a[i - 2][j];
			a[i][j + 1] += a[i][j] / 10;
			a[i][j] %= 10;
		}

		if (a[i][sa[i]] == 0) {
			sa[i]--;
		}
	}
	
	for (int i = sa[n]; i>=1; i--) {
		cout << a[n][i];
	}
}