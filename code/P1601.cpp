#include<iostream> 
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
char a[1001];
char b[1001];
int  aa[1001];
int bb[1001];
int sa, sb, sans;
int ans[1001];
int main() {
	cin >> a >> b;
	sa = strlen(a);
	sb = strlen(b);
	for (int i = 0; i < sa; i++) {
		aa[sa - i] = a[i] - '0';
	}
	for (int i = 0; i <= sb; i++) {
		bb[sb - i] =( b[i] - '0');
	}
	
	sans = max(sa, sb) + 1;
	
	for (int i = 1; i <= sans; i++) {
		ans[i] += aa[i] + bb[i];
		ans[i + 1] += ans[i] / 10;
		ans[i] %= 10;
	}

	if (ans[sans] == 0 ) {
		sans--;
	}
	for (int i = sans; i >= 1; i--) {
		cout << ans[i];
	}
}