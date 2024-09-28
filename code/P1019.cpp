#include<iostream>
using namespace std;
string s[22];
int n;

int used[22];int last,ans;
int find(int a, int b) {
	for (int i = s[a].length()-1; i >= 1; i--) {
		if (s[a][i] == s[b][0]) {
			for (int j = i + 1; j <= s[a].length()-1; j++) {
				if (s[a][j] != s[b][j - i]) {
					return 0;//因为不存在开头两个字母一样的英文单词 
				}
			}
			return s[a].length() - i ;
		}

	}
	return 0;
}



void search(int a) {
	for (int i = 1; i <= n; i++) {
		if (used[i] < 2 && find(a, i)) {
			used[i]++;
			ans += s[i].length() - find(a, i);
			search(i);
			used[i]--;
			ans -= s[i].length() - find(a, i);
		}
	}
	if (ans > last) {
		last = ans;
	}


}
int maxn;
char c;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
	}
	cin >> c;
	for (int i = 1; i <= n; i++) {
		if (s[i][0] == c) {
			used[i]++;
			ans += s[i].length();
			search(i);
			used[i]--;
			ans -= s[i].length();
			if (maxn < last) {
				maxn = last;
			}
		}
	}

	cout << maxn << endl;

}