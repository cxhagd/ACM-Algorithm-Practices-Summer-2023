#include<iostream>
#include<algorithm> 
using namespace std;
int n;

struct stu {
	int num;
	int x, y, z;
	int sum;
};
bool cmp(stu m, stu n) {
	if (m.sum > n.sum) {
		return 1;
	}
	if (m.sum < n.sum) {
		return 0;
	}
	if (m.sum == n.sum) {
		if (m.x > n.x) {
			return 1;
		}
		if (m.x < n.x) {
			return 0;
		}
		if (m.x == n.x) {
			return m.num < n.num;
		}
	}
}

stu a[501];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].x >> a[i].y >> a[i].z;
		a[i].sum = a[i].x + a[i].y + a[i].z;
		a[i].num = i;
	}
	sort(&a[1], &a[n + 1], cmp);
	for (int i = 1; i <= 5; i++) {
		cout << a[i].num << " " << a[i].sum << endl;

	}

}