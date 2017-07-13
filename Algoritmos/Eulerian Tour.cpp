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

stack<int> res;
bool grafo[MAXN][MAXN];
//u debe ser un vertice degrado impar o cualquier sihay ciclo
void dfs(int u){
	for(int v=0;v<n;v++){
		if(grafo[u][v]){
			grafo[u][v]=0;
			grafo[v][u]=0;
			dfs(v);
		}
	}
	res.push(u);
}

//sino usar
list<int> tour;
bool listo;
bool usada[MAXN][MAXN];
void euler_tour(list<int>::iterator i,int u){
	bool entro=false;
	for(int v=0;v<V;v++){
		if(u!=v && grafo[u][v] && !usada[u][v]){
			usada[u][v]=true;
			usada[v][u]=true;
			entro=true;
			euler_tour(tour.insert(i,u),v);
		}
	}
	//esto es para imprimir el ultimo elemento del camino/ciclo
	if(!entro && !listo){
		listo=true;
		tour.insert(i,u);
	}
}