#include<iostream> 
#include<queue>
using namespace std;
int N, M;

struct edge {
	int v, next = 0;
};
edge e[2000000+2];
struct Node {
	int pos;
	int dist = 0x7fffffff;
	long long int num = 0;
	bool operator>(const Node& x)const
	{
		return dist > x.dist;
	}
};
priority_queue<Node, vector<Node>, greater<Node>>q;
Node node[1000000+2];
int head[1000000+2];
int tot = 1;
bool vis[1001000];
void add_edge(int x, int y) {
	e[tot].v = y;
	e[tot].next = head[x];
	head[x] = tot++;
}
void dijkstra() {
	node[1].dist = 0;
	node[1].num = 1;
	q.push(node[1]);
	while (!q.empty()) {
		Node u = q.top();
		q.pop();
		int x = u.pos;
		if (vis[x])continue;
		vis[x] = 1;
		for (int i = head[x]; i; i = e[i].next) {
			int y = e[i].v;
			int dnew = node[x].dist + 1;
			if (dnew < node[y].dist) {
				if (node[y].dist == 0x7fffffff) {
					node[y].num += node[x].num;
					node[y].num %= 100003;
				}
				node[y].dist = dnew;
				q.push(node[y]);
			}else if (dnew == node[y].dist) {
				node[y].num+=node[x].num;
				node[y].num %= 100003;
			}
		}
	}

}
int main() {
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		int x, y;
		cin >> x >> y;
		add_edge(x, y);
		add_edge(y, x);
	}
	for (int i = 1; i <= N; i++) {
		node[i].pos = i;
	}

	dijkstra();

	for (int i = 1; i <= N; i++) {
		
			cout << (node[i].num ) % 100003 << endl;
		
		
	}
}