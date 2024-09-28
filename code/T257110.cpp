#include<iostream>
using namespace std;
int n;
int x[20];
bool y[20], c[50], d[50];
long long int ans = 0;
int ti = 0;
void print() {
	for (int i = 1; i <= n; i++) {
		cout << x[i] << " ";
	}
	cout << endl;
}

void find(int i) {
	if (i > n) {
		ans++;
		if (ti < 3) {
			print();
			ti++;
		}
		return;
	}
	for (int j = 1; j <= n; j++) {
		if ((!y[j]) && (!c[i + j - 1]) && (!d[n - i + j])) {
			x[i] = j;
			y[j] = 1;
			c[i + j - 1] = 1;
			d[n - i +j] = 1;
			find(i + 1);
			y[j] = 0;
			c[i + j - 1] = 0;
			d[n - i +j] = 0;
		}
	}
}

int main() {
	cin >> n;
	find(1);
	cout << ans;
}