#include<iostream>
#include<algorithm>
#include <cstring>
using namespace std;
int n = 0;
int a[100000 + 11], d[100000 + 11];
int len = 1;
void myflush() {
	memset(d, 0, sizeof(d));
	len = 1;
}


//最长不上升子序列的长度
int fun1() {
	myflush();
	d[1] = a[1];
	for (int i = 2; i <= n; i++) {
		if (a[i] <= d[len]) {
			d[++len] = a[i];
		}
		else {
			//在栈里从下往上找到第一个比自己小的，替换它
			int le = 1, ri = len;
			while (le < ri) {
				int mid = (le + ri) >> 1;
				if (a[i] > d[mid]) {
					ri = mid;
				}
				else {
					le = mid + 1;
				}
			}
			d[le] = a[i];
		}

	}
	return len;
}
//最长上升子序列的长度

int fun2() {
	myflush();
	d[1] = a[1];
	for (int i = 2; i <= n; i++) {
		if (a[i] > d[len]) {
			d[++len] = a[i];
		}
		else {
			int le = 1, ri = len;
			while (le < ri)
			{
				int mid = (le + ri) >> 1;
				if (a[i] <= d[mid]) {
					ri = mid;
				}
				else {
					le = mid + 1;
				}
			}
			d[le] = a[i];
		}
	}
	return len;
}

int main() {
	//读入未知长度的int数组：
	
	while (cin >> a[++n]);
	n--;


	cout << fun1()	<< endl << fun2()<< endl;
}