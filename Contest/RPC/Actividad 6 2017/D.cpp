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
#define MAXN 10010
#define LOG 21
int n;
LL ancho[MAXN];
LL alto[MAXN];
LL maxis[MAXN];
LL pos[MAXN];
LL acum[MAXN];
void sacar_maximos(){

	maxis[n]=n;
	pos[n]=n;
	int POS=n;
	LL maxi=alto[n];
	for(int i=n-1;i>=0;i--){
		int p=i+1;
		while(p<n && alto[i]>alto[p] && maxis[p]>=alto[p]){
			p=pos[p];
		}
		maxis[i]=alto[p];
		pos[i]=p;
	}
	/*
	cout<<"maximos"<<endl;
	for(int i=0;i<n;i++){
		cout<<pos[i]<<" "<<maxis[i]<<endl;	
	}
	*/
	
}

void acumulada(){
	acum[0]=0;
	for(int i=0;i<n;i++){
		acum[i+1]=acum[i]+ancho[i];
	}
}

int main(){
	int t;
	ileer(t);
	For(c,t){
		int a;
		i2leer(a,n);
		For(i,n){
			LLleer(ancho[i]);
		}
		for(int i=0;i<=n;i++){
			LLleer(alto[i]);
		}
		sacar_maximos();
		acumulada();
		LL res=0;
		int i=0;
		while(i<n){
			int ls=pos[i];
			LL alt=min(alto[i],alto[ls]);
			LL width=acum[ls]-acum[i];
			//cout<<i<<" rango "<<ls<<endl;
			//cout<<alt<<" espacio "<<width<<endl;
			res+=((LL)a)*alt*width;
			i=ls;
		}
		printf("%lld\n",res);

	}
}