#include<iostream>
#include<cstring>
using namespace std;
char a[1000000 + 11];
int sa;
int kmp[1000000 + 11] = { 0 };
int main() {
	cin >> sa;
	cin >> a + 1;
	int j = 0;

	for (int i = 2; i <= sa; i++) {
		while (j && a[i] != a[j + 1]) {
			j = kmp[j];
		}
		if (a[j + 1] == a[i]) {
			j++;
			kmp[i] = j;
		}

	}
	cout << sa - kmp[sa];
	cout << endl;
}