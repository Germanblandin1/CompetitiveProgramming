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
	LL peso,costo;
	nodo(){}
	nodo(int a,LL b,LL c){
		des=a;
		peso=b;
		costo=c;
	}
	bool operator <(const nodo &ot)const{
		if(peso==ot.peso) return costo>ot.costo;
		return peso>ot.peso;
	}	
};

bool operator <(Pii &A,Pii &B){
	if(A.F==B.F)return A.S<B.S;
	return A.F<B.F;
}


vector<nodo> grafo[MAXN];
Pii matriz[MAXN];
int padre[MAXN];

void disjktra(){
	n++;
	priority_queue<nodo> cola;
	for(int i=0;i<n;i++) matriz[i]=MK(INF,INF);
	matriz[0]=MK(0,0);
	padre[0]=-1;
	cola.push(nodo(0,0,0));
	while(!cola.empty()){
		nodo actual=cola.top();cola.pop();
		int u=actual.des;
		LL peso=actual.peso;
		LL costo=actual.costo;
		for(int i=0;i<grafo[u].size();i++){
			int v=grafo[u][i].des;
			LL npeso=grafo[u][i].peso;
			LL ncosto=grafo[u][i].costo;
			Pii suma=MK(peso+npeso,costo+ncosto);
			if(suma<matriz[v]){
				matriz[v]=suma;
				padre[v]=u;
				cola.push(nodo(v,suma.F,suma.S));
			}
		}
	}
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
		grafo[ini].PB(nodo(des,1LL,cos));
		grafo[des].PB(nodo(ini,1LL,cos));
		//cout<<ini<<" "<<des<<" "<<cos<<endl;
	}
	disjktra();
	priority_queue<nodo> cola;
	for(int i=0;i<n;i++){
		cola.push(nodo(i,matriz[i].F,matriz[i].S));
	}

	LL total=0LL;
	while(!cola.empty() && total>=0){
		nodo actual=cola.top();cola.pop();
		int u=actual.des;
		if(matriz[u].S>=INF){ total=-1; break;}
		total+=matriz[u].S-(padre[u]==-1?0:matriz[padre[u]].S);
	}
	if(total>=0){
		printf("%lld\n",total);
	}else{
		printf("Impossible\n");
	}
	
	
	
}