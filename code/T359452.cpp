#include<iostream>
using namespace std;
int ot[13];

int ptin;
int last = 0;
int lv = 0;

int cnt(int last, int out) {
	if (300 + last - out >= 100) {
		return (int)((300 + last - out) / 100) * 100;
	}
	else {
		return 0;
	}
}

int main() {
	for (int i = 1; i <= 12; i++) {
		cin >> ot[i];
		ptin += cnt(last, ot[i]);
		lv = last + 300 - ot[i] - cnt(last, ot[i]);
		if (lv < 0) {
			cout << "-" << i;
			return 0;
		}
		last = lv;
	}
	cout << last + 1.2 * ptin;

}