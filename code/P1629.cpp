#include<iostream> 
#include<queue>
#include<set>
#include<map>
using namespace std;
struct Node {
	int pos;
	long long int dist = 0x7fffffff;//dist 不够大

	bool operator>(const Node& x)const
	{
		return dist > x.dist;
	}
};
priority_queue<Node, vector<Node>, greater<Node>>q; //怎么排序 
Node node[2011];
Node node2[2011];
int head[2011];
int head2[2011];
struct edge {
	int v, w, next = 0;
};
int n, m ;
int tot = 1;//边的序号末尾 
int tot2 = 1;
edge e[100010];
edge e2[100010];
inline void add_edge(int u, int v, int w) {
	e[tot].v = v;
	e[tot].w = w;
	e[tot].next = head[u];
	head[u] = tot++;
}
inline void add_edge2(int u, int v, int w) {
	e2[tot2].v = v;
	e2[tot2].w = w;
	e2[tot2].next = head2[u];
	head2[u] = tot2++;
}
bool vis[1011];
bool vis2[1011];
inline void dijkstra(int s) {

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
inline void dijkstra2(int s) {

	node2[s].dist = 0;
	q.push(node2[s]);
	while (!q.empty()) {
		Node u = q.top();//node的序号是在这里赋值的   u->v
		q.pop();
		int x = u.pos;
		if (vis2[x])continue;
		vis2[x] = 1;
		for (int i = head2[x]; i; i = e2[i].next) {//考虑u->v要不要加序号为 i的边 	
			int y = e2[i].v;
			int dnew = node2[x].dist + e2[i].w;
			if (dnew < node2[y].dist) {
				node2[y].dist = dnew;
				q.push(node2[y]);
			}
		}
	}
}
long long int ans = 0;
int main() {
	cin >> n >> m ;
	
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		int a = q.size();
		add_edge(u, v, w);
		add_edge2(v, u, w);
	}
	for (int i = 1; i <= n; i++) {
		node[i].pos = i;
		node2[i].pos = i;
	}
	dijkstra(1);

	for (int i = 1; i <= n; i++) {
		ans += node[i].dist;
	}
	dijkstra2(1);
	for (int i = 1; i <= n; i++) {
		ans += node2[i].dist;
	}
	cout << ans << endl;
}