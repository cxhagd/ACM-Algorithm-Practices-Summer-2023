#include<iostream>
#include<cstring>
//一个不靠题解的答案
using namespace std;
int trie[3000 + 11][5011][27];
int cnt[3000 + 11][5011] = {0};
int id[3000 + 11];
int map(char x) {
	if (x >= 'A' && x <= 'Z') {
		return x - 'A';
	}
	if (x >= 'a' && x <= 'z') {
		return x - 'a' + 26;
	}
}
void insert(char str[], int j) {
	int p = 0, len = strlen(str);
	for (int i = 0; i < len; i++) {
		int c = map(str[i]);
		if (!trie[j][p][c]) {
			trie[j][p][c] = ++id[j];
		}
		p = trie[j][p][c];
	}
	cnt[j][p]++;
}

int find(char str[], int j) {
	int p = 0;
	int len = strlen(str);

	for (int i = 0; i < len; i++) {
		int c = map(str[i]);
		if (!trie[j][p][c]) {
			return 0;
		}
		p = trie[j][p][c];
	}

	return cnt[j][p];
}
int N, M, L[1000 + 11]; char s[25];
int main() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> L[i];
		for (int j = 1; j <= L[i]; j++) {
			cin >> s;
			insert(s, i);
		}
	}
	cin >> M;
	for (int i = 1; i <= M; i++) {
		cin >> s;
		for (int j = 1; j <= N; j++) {
			if (find(s, j)) {
				cout << j << " ";
			}
		}
		cout << endl;
	}

	return 0;
}