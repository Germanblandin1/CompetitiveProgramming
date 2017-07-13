#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define DINF 1e10
#define EPS 1e-15
#define PII acos(-1)
#define LL long long
#define Pii pair<int,int>
#define For(i,n) for(int i=0;i<n;i++)
#define ileer(n) scanf("%d",&n)
#define LLleer(n) scanf("%lld",&n)
#define i2leer(n,m) scanf("%d %d",&n,&m)
#define fleer(n) scanf("%lf",&n)
#define f2leer(n,m) scanf("%Lf %Lf",&n,&m)
#define MK make_pair
#define PB push_back
#define llenar(arr,val) memset(arr,val,sizeof(arr))
#define VLL vector< LL >
#define matrix vector<VI >
#define F first
#define S second
#define MAXN 110
#define LOG 21


struct Edge {
  int u, v;
  LL cap, flow;
  Edge() {}
  Edge(int u, int v, LL cap): u(u), v(v), cap(cap), flow(0) {}
};

struct Dinic {
  int N;
  vector<Edge> E;
  vector<vector<int>> g;
  vector<int> d, pt;
  
  Dinic(int N): N(N), E(0), g(N), d(N), pt(N) {}

  void AddEdge(int u, int v, LL cap) {
    if (u != v) {
      E.emplace_back(Edge(u, v, cap));
      g[u].emplace_back(E.size() - 1);
      E.emplace_back(Edge(v, u, 0));
      g[v].emplace_back(E.size() - 1);
    }
  }

  bool BFS(int S, int T) {
    queue<int> q({S});
    fill(d.begin(), d.end(), N + 1);
    d[S] = 0;
    while(!q.empty()) {
      int u = q.front(); q.pop();
      if (u == T) break;
      for (int k: g[u]) {
        Edge &e = E[k];
        if (e.flow < e.cap && d[e.v] > d[e.u] + 1) {
          d[e.v] = d[e.u] + 1;
          q.emplace(e.v);
        }
      }
    }
    return d[T] != N + 1;
  }

  LL DFS(int u, int T, LL flow = -1) {
    if (u == T || flow == 0) return flow;
    for (int &i = pt[u]; i < g[u].size(); ++i) {
      Edge &e = E[g[u][i]];
      Edge &oe = E[g[u][i]^1];
      if (d[e.v] == d[e.u] + 1) {
        LL amt = e.cap - e.flow;
        if (flow != -1 && amt > flow) amt = flow;
        if (LL pushed = DFS(e.v, T, amt)) {
          e.flow += pushed;
          oe.flow -= pushed;
          return pushed;
        }
      }
    }
    return 0;
  }

  LL MaxFlow(int S, int T) {
    LL total = 0;
    while (BFS(S, T)) {
      fill(pt.begin(), pt.end(), 0);
      while (LL flow = DFS(S, T))
        total += flow;
    }
    return total;
  }
};


int n,m,p;
bool categoria[MAXN];
//0 es el source
// [1 a n] son los mounstros
// [n+1, n+m] son los juguetes
// [n+m+1,n+m+p] son las categorias
// n+m+p+1 es el sink

int main(){
	llenar(categoria,false);
	i2leer(n,m); ileer(p);
	int N=n+m+p+2;
	int source=0;
	int sink=n+m+p+1;
	
	Dinic dinic(N);
	For(i,n){
		int k;
		ileer(k);
		For(j,k){
			int a;
			ileer(a);
			a--;
			dinic.AddEdge(i+1,n+1+a, 1);
		}
		dinic.AddEdge(source,i+1,1);
	}
	For(i,p){
		int k,r;
		ileer(k);
		For(j,k){
			int a;
			ileer(a);
			a--;
			dinic.AddEdge(n+1+a,n+m+1+i, 1);
			categoria[a]=true;
		}
		ileer(r);
		dinic.AddEdge(n+m+1+i, sink,r);
	}
	for(int i=0;i<m;i++){
		if(!categoria[i]){
			dinic.AddEdge(n+1+i, sink,1);
		}
	}
	int maxi=dinic.MaxFlow(source,sink);
	printf("%d\n",maxi);
}