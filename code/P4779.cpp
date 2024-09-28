#include<iostream> 
#include<queue>
#include<set>
#include<map>
using namespace std;
struct Node {
	int pos;
	int dist = 0x7fffffff;//dist 不够大

	bool operator>(const Node& x)const
	{
		return dist > x.dist;
	}
};
priority_queue<Node, vector<Node>, greater<Node>>q; //怎么排序 
Node node[100100];
int head[100100];

struct edge {
	int v, w, next = 0;
};
int n, m, s;
int tot = 1;//边的序号末尾 
edge e[500010];
inline void add_edge(int u, int v, int w) {
	e[tot].v = v;
	e[tot].w = w;
	e[tot].next = head[u];
	head[u] = tot++;
}
bool vis[100100];
inline void dijkstra() {

	node[s].dist = 0;
	q.push(node[s]);
	while (!q.empty()) {
		Node u = q.top();//node的序号是在这里赋值的   u->v
		q.pop();
		int x = u.pos;
		if (vis[x])continue;
		vis[x] = 1;
		for (int i = head[x]; i; i = e[i].next) {//考虑u->v要不要加序号为 i的边 	
			int y = e[i].v;
			int dnew = node[x].dist + e[i].w;
			if (dnew < node[y].dist) {
				node[y].dist = dnew;
				q.push(node[y]);
			}
		}
	}
}

int main() {
	cin >> n >> m >> s;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		add_edge(u, v, w);
	}
	for (int i = 1; i <= n; i++) {
		node[i].pos = i;
	}
	dijkstra();

	for (int i = 1; i <= n; i++) {
		cout << node[i].dist << " ";
	}
}