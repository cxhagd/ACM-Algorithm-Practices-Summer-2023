#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm> 
#include<cstring>
#include<cstdio>
#include<cstdlib>

using namespace std;
int a[1001], b[1001];
char ca[1001], cb[1001];
int a2;
int b2;
int l;
int ma = 0, mb = 0, m = 0;
int ans[1001];
int main() {
	scanf("%s", ca);
	scanf("%s", cb);

	a2 = strlen(ca);
	b2 = strlen(cb);
	//已经转置了！！！！！！！！！！！！！！！！！！！
	for (int i = 0; i < a2; i++) {
		a[a2 - i] = ca[i] - '0';
		ma = max(ma, a[a2 - i]);
	}
	for (int i = 0; i < b2; i++) {
		b[b2-i] = cb[i] - '0';
		mb = max(mb, b[b2 - i]);
	}
	m = max(ma, mb) + 1;
	l = max(a2, b2) + 1;
	for (int i =1; i<=l; i++) {
		ans[i] += a[i] + b[i];
		ans[i + 1] += ans[i] / m;
		ans[i] %= m;
	}
	if (ans[l] == 0) {
		l--;
	}
	cout << l;
}