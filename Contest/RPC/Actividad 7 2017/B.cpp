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
#define MAXN 1010
#define LOG 21
char cad[MAXN];
string jugadores[11];
map<string,int> mapa;
map<Pii,int> equipos;
Pii requipos[110];
int n;

class nodo{
	public:
	int r,t,e;
	nodo(){}
	nodo(int a,int b,int c){
		r=a;
		t=b;
		e=c;
	}
	bool operator <(const nodo & ot)const{
		if(r==ot.r) return t<ot.t;
		return r>ot.r;
	}
};


int main(){
	ileer(n);
	For(i,n){
		scanf("%s",cad);
		jugadores[i]=cad;
		mapa[jugadores[i]]=i;
	}
	int N=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==j) continue;
			equipos[MK(i,j)]=N;
			requipos[N++]=MK(i,j);
		}
	}
	
	Pii tiempoW=MK(0,2);
	Pii blanco=MK(0,2);
	Pii negro=MK(1,3);
	Pii tiempoB=MK(1,3);
	int white=equipos[blanco]; //0
	int black=equipos[negro];  //1
	queue<int> cola;
	for(int i=4;i<n;i++) cola.push(i);
	scanf("%s",cad);
	int m=strlen(cad);
	char ant=cad[0];
	int racha=0;
	vector<nodo> solucion;
	for(int i=0;i<=m;){
		if(i==m || ant!=cad[i]){
			Pii original;
			Pii originalT;
			if(ant=='W'){ original=blanco; originalT=tiempoW;}
			else { original=negro; originalT=tiempoB;}
			if(originalT.F>originalT.S)
				swap(original.F,original.S);
			
			solucion.PB(nodo(racha,i,equipos[original]));
			racha=0;
			ant=cad[i];
			if(i==m) break;
		}else{
			int pend=cola.front();cola.pop();
			if(cad[i]=='W'){
				swap(blanco.F,blanco.S);
				swap(tiempoW.F,tiempoW.S);
				cola.push(negro.S);
				negro=MK(pend,negro.F);
				tiempoB=MK(i+4,tiempoB.F);
			}else{
				swap(negro.F,negro.S);
				swap(tiempoB.F,tiempoB.S);
				cola.push(blanco.S);
				blanco=MK(pend,blanco.F);
				tiempoW=MK(i+4,tiempoW.F);
			}
			racha++;
			i++;
		}
	}
	sort(solucion.begin(),solucion.end());
	int maxi=solucion[0].r;
	for(int i=0;i<solucion.size() && maxi==solucion[i].r;i++){
		Pii equipo=requipos[solucion[i].e];
		printf("%s %s\n",jugadores[equipo.F].c_str(),jugadores[equipo.S].c_str());
	}
	
	
}