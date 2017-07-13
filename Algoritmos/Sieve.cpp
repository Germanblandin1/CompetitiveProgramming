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
#define MAXN 10000001

int p[MAXN];
int criba(int n){
	llenar(p,0);
	for(int i=4;i<=n;i+=2){
		p[i]=2;
	}
	for(int i=3;i*i<=n;i+=2){
		if(!p[i]){
			for(int j=i*i;j<=n;j+=2*i) 
				p[j]=i;
		}
	}
	
}

int F=0;  //cantidad de factores
int f[MAXN]; //factores
int e[MAXN]; //se supone que los exponentes
int fact(int n){
	
	while(p[n]){
		f[F++]=p[n];
		n/=p[n];
	}
	f[F++]=n;
	//sort(f,f+F);
	return F;
	
}


//ESTO NO ESTA PROBADO y no parece funcionar bien
int D; //cantidad de divisores
int d[MAXN]; //divisores
void divisores(int cur,int s,int e){
	if(s==e) d[D++]=cur;
	else{
		int m;
		for(m=s+1;m<e && f[m]==f[s];m++){
			for(int i=s;i<=m;i++){
				divisores(cur,m,e);
				cur*=f[s];
			}
		}
		
	}
	
}




