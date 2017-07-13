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
#define MAXN 3000
#define LOG 21

vector<int> grafo[MAXN];
vector<int> rgrafo[MAXN];
vector<int> orden;
int can_comp;// cantidad de componentes
int comp[MAXN]; // dice a que componente pertenece
int size_comp[MAXN]; //cuantos nodos tiene cada cada componente;
bool visitado[MAXN]; 

void dfs_topo(int u){
	visitado[u]=true;
	for(int i=0;i<grafo[u].size();i++){
		int v=grafo[u][i];
		if(!visitado[v]){
			dfs_topo(v);
		}
	}
	orden.PB(u);
}

void dfs_rever(int u){
	visitado[u]=true;
	size_comp[can_comp]++;
	comp[u]=can_comp;
	for(int i=0;i<rgrafo[u].size();i++){
		int v=rgrafo[u][i];
		if(!visitado[v]{
			dfs_rever(v);
		}
	}
}


int Kosaraju(){
	llenar(size_comp,0);
	can_comp=0;
	
	llenar(visitado,false);
	for(int i=0;i<n;i++){
		if(!visitado[i]){
			dfs_topo(i);
		}
	}
	
	llenar(visitado,false);
	for(int i=0;i<orden.size();i++){
		if(!visitado[i]){
			dfs_rever(i);
			can_comp++;
		}
	}
	
	return can_comp;
	
}


