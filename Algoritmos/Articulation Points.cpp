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
int raiz;
int Tin[MAXN]; //T-in
int Tmin[MAXN]; //T-min
vector<int> grafo[MAXN];
bool visitado[MAXN];
void dfs_PA(int u,int p){
	t++;
	Tin[u]=t;
	Tmin[u]=t;
	visitado[u]=true;
	int veces=0;
	for(int i=0;i<grafo[u].size();i++){
		int v=grafo[u][i];
		if(v==p) continue;
		if(!visitado[v]){
			veces++;
			dfs(v,u);
			Tmin[u]=min(Tmin[u],Tmin[v]);
			
			if(Tmin[v]>Tin[u]){
				//(u,v) es un puente
			}
			if((Tmin[v]>=Tin[u] && p!=-1)){
				//v es un punto de articulacion
			}
				
			
		}else{
			Tmin[u]=min(Tmin[u],Tmin[v]);
		}
		
	}
	if(p==-1 && veces>1){
		//la raiz es punto de articulacion
	}
}


