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
#define MAXN 30
int X,A,D,n;
int XP[MAXN];
int AP[MAXN];
int DP[MAXN];
char cad[1000];

class nodo{
	public:
	int x,a,d;
	nodo(){}
	nodo(int aa,int b,int c){
		x=aa;
		a=b;
		d=c;
	}
	bool operator <(const nodo &ot)const{
		if(x==ot.x){
			if(a==ot.a) return d<ot.d;
			return a<ot.a;
		}
		return x<ot.x;
	}
	
	nodo operator +(const nodo &ot)const{
		return nodo(x+ot.x,a+ot.a,d+ot.d);
	}
	
};

nodo mision[MAXN];

int main(){
	int t;
	ileer(t);
	For(c,t){
		i2leer(X,A);
		i2leer(D,n);
		for(int i=0;i<n;i++){
			
			scanf("%*s %d %d %d",&mision[i].x,&mision[i].a,&mision[i].d);
		}
		int mitad=n/2;
		int mitad2=n-mitad;
		vector<nodo> mapa1;
		for(int mask=0;mask<=(1<<mitad)-1;mask++){
			nodo actual=nodo(0,0,0);
			for(int i=0;i<mitad;i++){
				if(mask&(1<<i)){
					actual=actual+mision[i];
				}
			}
			mapa1.PB(actual);
		}
		
		set<nodo> mapa2;
		for(int mask=0;mask<=(1<<mitad2)-1;mask++){
			nodo actual=nodo(0,0,0);
			for(int i=0;i<mitad2;i++){
				if(mask&(1<<i)){
					actual=actual+mision[i+mitad];
				}
			}
			mapa2.insert(actual);
		}
		
		set<nodo>::iterator it,it2;
		bool sepuede=false;
		for(int i=0;i<mapa1.size();i++){
			nodo actual=mapa1[i];
			if(actual.x>X || actual.a>A || actual.d>D) continue;
			nodo sig=nodo(X-actual.x,A-actual.a,D-actual.d);
			it2=mapa2.find(sig);
			if(it2!=mapa2.end()) sepuede=true;
		}
		printf("%s\n",sepuede?"POSSIBLE":"IMPOSSIBLE");
		
		
	}
}