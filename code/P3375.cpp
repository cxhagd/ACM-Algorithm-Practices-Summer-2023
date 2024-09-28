#include<iostream>
#include<cstring>
using namespace std;
char a[1000000 + 11];
char b[1000000 + 11];
int kmp[1000000 + 11] = { 0 };
int main() {
	cin >> a + 1 >> b + 1;
	int j = 0;
	int sa = strlen(a + 1);
	int sb = strlen(b + 1);
	for (int i = 2; i <= sb; i++) {
		while (j && b[i] != b[j + 1]) {
			j = kmp[j];
		}
		if (b[j + 1] == b[i]) {
			j++;
			kmp[i] = j;
		}

	}
	j = 0;
	for (int i = 1; i <= sa; i++) {
		while (j && b[j + 1] != a[i]) {
			j = kmp[j];
		}
		if (b[j + 1] == a[i]) {
			j++;
		}
		if (j == sb) {
			cout << i - sb + 1 << endl;
			j = kmp[j];
		}
	}
	for (int i = 1; i <= sb; i++) {
		cout << kmp[i] << " ";
	}
	cout << endl;
}