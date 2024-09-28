#include<iostream>
using namespace std;
long long int n;
long long int a[1001], b[1001];

bool jud = 1;
int main() {
	cin >> n;
	int s = 0;
	for (int i = 1; n > 0; i++, s++) {
		a[i] = n % 2;
		n = n / 2;
	}

	for (int i = 1; i <= s; i++) {
		b[s + 1 - i] = a[i];
	}
	for (int i = 1; i <= s; i++) {
		if (a[i] == b[i]) {
			jud=1;
		}
		else {
			jud = 0;
			break;
		}
	}
	if (jud) {
		cout << "Yes\n";
	}
	else {
		cout << "No\n";
	}
}