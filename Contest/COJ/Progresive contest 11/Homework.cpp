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
#define MAXN 30001
#define LOG 21


map<int,int> mapa;
void precarga(int n){
	int val=6;
	int dif=4;
	mapa[3]=1;
	mapa[6]=2;
	for(int i=3;val+dif<=n;i++){
		mapa[val+dif]=i;
		val=val+dif;
		dif++;
	}
	
}

int main(){
	precarga(50000000);
	int t;
	ileer(t);
	For(c,t){
		int n;
		ileer(n);
		if(mapa.count(n)!=0)
			printf("%d\n",mapa[n]);
		else printf("No solution\n");
		
	}
}