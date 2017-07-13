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
#define MAXN 3001
#define LOG 21

char cad[100];

class nodo{
	public:
	int ori,val,pri;
	nodo(){}
	nodo(int a,int b,int c){
		val=a;
		pri=b;
		ori=c;
	}
	
	bool operator <(const nodo &ot)const{
		if(val==ot.val) return pri>ot.pri;
		return val>ot.val;
	}
	
};
string mapa[MAXN];
int main(){
	int t;
	ileer(t);
	For(c,t){
		int n;
		int k;
		i2leer(n,k);
		priority_queue<nodo> cola;
		for(int i=0;i<n;i++){
			int v;
			scanf("%s %d",cad,&v);
			string g=cad;
			mapa[i]=g;
			cola.push(nodo(v,i,v));
		}
		vector<nodo> res;
		while(res.size()<k){
			nodo actual=cola.top();cola.pop();
			res.push_back(actual);
			cola.push(nodo(actual.val+actual.ori,actual.pri,actual.ori));
		}
		
		for(int i=0;i<k;i++){
			printf("%d %s\n",res[i].val,mapa[res[i].pri].c_str());
		}

	}
}