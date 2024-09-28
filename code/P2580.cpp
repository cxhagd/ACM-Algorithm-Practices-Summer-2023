#include<iostream>
#include<cstring>
//一个不靠题解的答案
using namespace std;
int trie[1000000 + 11][100];
int cnt[1000000 + 11] = { 0 };
int id;
bool vis[1000000 + 11];
int map(char x) {
	if (x >= 'a' && x <= 'z') {
		return x - 'a' + 26;
	}
	return 1;
}
void insert(char str[]) {
	int p = 0, len = strlen(str);
	for (int i = 0; i < len; i++) {
		int c = map(str[i]);
		if (!trie[p][c]) {
			trie[p][c] = ++id;
		}
		p = trie[p][c];
	}
	cnt[p]++;
}

int find(char str[]) {
	int p = 0;
	int len = strlen(str);

	for (int i = 0; i < len; i++) {
		int c = map(str[i]);
		if (!trie[p][c]) {
			return 0;
		}
		p = trie[p][c];
	}
	if (cnt[p]) {
		
		return p;
	}
	else {
		return 0;
	}
}
int n, m; char s[111];
int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> s;
		insert(s);
		memset(s, '\0', sizeof(s));
	}
	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> s;
		int res = find(s);
		if (res && !vis[res]) {
			vis[res] = 1;
			cout << "OK" << endl;
		}
		else {
			if (!res) {
				cout << "WRONG" << endl;
				continue;
			}
			else {
				if (res && vis[res]) {
					cout << "REPEAT" << endl;
				}
			}
		}
		memset(s, '\0', sizeof(s));
	}

	return 0;
}