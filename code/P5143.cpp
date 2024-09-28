#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int N;

double s = 0;
struct poi {
	int x, y, z;
};
poi dot[50010];
bool cmp(poi a, poi b) {
	return a.z < b.z;
}
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> dot[i].x >> dot[i].y >> dot[i].z;
	}
	sort(&dot[1], &dot[N + 1], cmp);
	int n = N - 1;
	for (int i = 1; i <= N - 1; i++) {
		s += sqrt((dot[i + 1].x - dot[i].x) * (dot[i + 1].x - dot[i].x) + (dot[i + 1].y - dot[i].y) * (dot[i + 1].y - dot[i].y) + (dot[i + 1].z - dot[i].z) * (dot[i + 1].z - dot[i].z));
	}
	printf("%.3f", s);
}