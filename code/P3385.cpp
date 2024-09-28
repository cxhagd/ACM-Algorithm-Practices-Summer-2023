#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int T;
struct edge {
	int v, w, next = 0;
};
edge e[6010];

queue<int>q;
int tot =1;
struct Node {
	int pos;
	int dist = 0x7fffffff;//dist 不够大
	int cnt;
};
int n, m;
Node node[2010];

int head[2010];
bool inln[2010] = { 0 };
inline void add_edge(int u, int v, int w) {
	e[tot].v = v;
	e[tot].w = w;
	e[tot].next = head[u];
	head[u] = tot++;
}

bool spfa()  {
	q = queue<int>();
	node[1].dist = 0;
	node[1].cnt = 0;
	inln[1] = 1;
	q.push(1);
	while (!q.empty()) {
		int x = q.front();

		q.pop();
		inln[x] = 0;
		for (int i = head[x]; i; i = e[i].next) {
			int y = e[i].v;
			int dnew = node[x].dist + e[i].w;
			
			if (dnew < node[y].dist) {
				node[y].cnt =node[x].cnt + 1;
				node[y].dist = dnew;
				if (!inln[y]) {
				    if (node[y].cnt >= n) {
				    	return 1;
			    	}
					q.push(y);
					inln[y] = 1;
				}
			}
		}
	}
	return 0;
}
int u, v, w;
int main() {
	cin >> T;
	for (int ii = 1; ii <= T; ii++){
		cin >> n >> m;
		for (int i = 1; i <= m; i++) {
			
			cin >> u >> v >> w;
			if (w >= 0) {
				add_edge(u, v, w);
				add_edge( v, u, w);
			}
			else {
				add_edge(u, v, w);
			}
		}
		for (int i = 1; i <= n; i++) {
			node[i].pos = i;
		}
		if (spfa()) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
		
		tot = 1;
		memset(node, 0, sizeof(node));
		memset(e, 0, sizeof(e));
		memset(head, 0, sizeof(head));
		for (int i = 0; i <= 2002; i++)node[i].dist = 0x7fffffff;
		memset(inln, 0, sizeof(inln));
	}
}