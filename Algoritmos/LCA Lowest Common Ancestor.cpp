#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define INFNEG -2000000000000000001LL
#define DINF 1e10
#define EPS 1e-15
#define PII acos(-1)
#define LL long long
#define Pii pair<int,int>
#define For(i,n) for(int i=0;i<n;i++)
#define ileer(n) scanf("%d",&n)
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
#define MAXN 30001
#define LOG 21
int n;
int t=0; //inicialmente esta en 0
int Tin[MAXN]; //T-in
int Tout[MAXN]; //T-out
int d[MAXN][LOG];
vector<int> grafo[MAXN];

void dfs_LCA(int u,int p){
	t++;
	Tin[u]=t;
	d[u][0]=p;
	for(int i=0;i<grafo[u].size();i++){
		int v=grafo[u][i];
		if(v!=p){
			dfs(v,u);
		}
	}
	t++;
	Tout[u]=t;
}

bool esAncestro(int u,int v){
	if(Tin[u]<Tin[v] && Tin[v]<Tout[v] && Tout[v]<Tout[u]) return true;
	return false;
}


void preload_LCA(int root){
	dfs_LCA(root);
	for(int i=1;i<LOG;i++){
		for(int v=0;v<n;v++){
			d[v][i]=d[d[v][i-1]][i-1];
		}
	}
	
}

void LCA(int u,int v){
	if(esAncestro(u,v)) return u;
	if(esAncestro(v,u)) return v;
	
	for(int i=LOG-1;i>=1;i--){
		if(!esAncestro(d[u][i],v)){
			u=d[u][i];
		}
	}
	return d[u][0];
}

