#include<bits/stdc++.h>
#define lll __uint128_t
using namespace std;
string s;
int k;
char beg[17];
char ed[17];
bool flag[111] = { 0 };

lll ans = 1;
int temp;
void out(lll x) {//int128输出要自己写
	if (x > 9)out(x / 10);
	putchar(x % 10 + 48);
}
void dfs(char bg) {
	if (flag[bg]) {
		return;
	}
	else {
		flag[bg] = 1;
		for (int i = 1; i <= k; i++) {
			if (bg == beg[i]) {
				dfs(ed[i]);
			}
		}
	}

}


int main() {
	cin >> s;
	cin >> k;
	for (int i = 1; i <= k; i++) {
		cin >> beg[i] >> ed[i];
	}
	//先搜索最高位，最高位不能为0
	dfs(s[0]);
	for (char c = '1'; c <= '9'; c++) {
		if (flag[c]) {
			temp++;
		}
	}
	ans *= temp;
	temp = 0;
	memset(flag, 0, sizeof(flag));

	for (int i = 1; i <= s.length() - 1; i++) {
		dfs(s[i]);
		for (char c = '0'; c <= '9'; c++) {
			if (flag[c]) {
				temp++;
			}
		}
		if (temp) {
			ans *= temp;
			temp = 0;
			memset(flag, 0, sizeof(flag));

		}
		
	}out(ans);
}