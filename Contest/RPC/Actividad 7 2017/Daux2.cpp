#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f3f3f3f3fLL
#define DINF 1e10
#define EPS 1e-15
#define PII acos(-1)
#define LL long long
#define Pii pair<long long,long long>
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
char cad[1000];
int n;

class nodo{
	public:
	int des;
	LL peso;
	nodo(){}
	nodo(int a,LL b){
		des=a;
		peso=b;
	}
	
	bool operator <(const nodo &ot)const{
		return peso<ot.peso;
	}
	
};

vector<nodo> grafo[MAXN];
LL matriz[MAXN];
bool marca[MAXN];
LL  disjktra(){
	n++;
	LL total=0;
	queue<int> cola;
	llenar(marca,false);
	for(int i=0;i<n;i++) matriz[i]=INF;
	matriz[0]=0;
	marca[0]=true;
	cola.push(0);
	while(!cola.empty()){
		int u=cola.front();cola.pop();
		vector<nodo> nivel;
		for(int i=0;i<grafo[u].size();i++){
			int v=grafo[u][i].des;
			LL costo=grafo[u][i].peso;
			
			if(!marca[v]){
				nivel.PB(nodo(v,costo));
			}
		}
		sort(nivel.begin(),nivel.end());
		for(int i=0;i<nivel.size();i++){
			if(!marca[nivel[i].des]){
				marca[nivel[i].des]=true;
				total+=nivel[i].peso;
				cola.push(nivel[i].des);
			}
		}
	}
	for(int i=0;i<n;i++){
		if(matriz[i]>=INF) return -1;
	}
	return total;

}



int main(){
	map<string,int> mapa;
	int m;
	i2leer(n,m);
	mapa["English"]=0;
	For(i,n){
		grafo[i].clear();
		scanf("%s",cad);
		string g=cad;
		mapa[g]=i+1;
	}
	for(int i=0;i<m;i++){
		scanf("%s",cad);
		string sini=cad;
		LL cos;
		scanf("%s %lld",cad,&cos);
		string sdes=cad;
		int ini=mapa[sini];
		int des=mapa[sdes];
		grafo[ini].PB(nodo(des,cos));
		grafo[des].PB(nodo(ini,cos));
		//cout<<ini<<" "<<des<<" "<<cos<<endl;
	}
	LL total=disjktra();

	if(total>=0){
		printf("%lld\n",total);
	}else{
		printf("Impossible\n");
	}
	
	
	
}