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
#define MAXN 101
#define MAXM 1001
#define LOG 21
int n;
int val[MAXN];

int gcd(int a,int b){
	if(b==0) return a;
	if(a==0) return b;
	return gcd(b,a%b);
}

int matriz[MAXN][MAXM];
bool marca[MAXN][MAXM];
list<int> lista;

int dp(int c,int g){
	if(c==2) return gcd(lista.front(),lista.back());
	int &mejor=matriz[c][g];
	if(marca[c][g]) return mejor;
	marca[c][g]=true;
	mejor=INF;
	list<int>::iterator it,aux;
	list<int>::iterator itI;
	list<int>::iterator itF;
	cout<<"comienza"<<endl;
	for(it=lista.begin();it!=lista.end();){
		int val=*it;
		cout<<c<<" "<<val<<endl;
		int X;cin>>X;
		aux=it;
		aux++;
		itI= aux==lista.end()?lista.begin():aux;
		aux--;
		int vant;
		if(aux==lista.begin()){
			vant=lista.back();
		}else{
			vant=*aux;
		}
		aux++;
		int vsig=*(itI);
		int ng=gcd(vsig,vant);
		list<int>::iterator it2=lista.erase(it);
		mejor=min(mejor,dp(c-1,ng)+ng);
		it=lista.insert(it2,val);
		it--;
	}
	cout<<"termina"<<endl;
	return mejor;
	
}


int main(){
	while(ileer(n),n){
		For(i,n){
			ileer(val[i]);
			lista.PB(val[i]);
		}
		llenar(marca,false);
		printf("%d\n",dp(n,1));
	}
}