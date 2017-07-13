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
#define MAXN 50
#define LOG 21

int pos[MAXN];
int n;
LL can=0;
bool invalido=false;
void contar(int disco,int ini,int aux,int fin){
	if(disco==0) return;
	if(pos[disco]==fin){
		can+=((1LL<<((LL)disco-1LL)));
		contar(disco-1,aux,ini,fin);
	}else if(pos[disco]==aux){
		invalido=true;
	}else{
		contar(disco-1,ini,fin,aux);
	}
	
}


int main(){
	llenar(pos,0);
	n=0;
	for(int i=0;i<3;i++){
		int k;
		ileer(k);
		For(j,k){
			int a;
			ileer(a);
			pos[a]=i+1;
			n++;
		}
	}

	invalido=false;
	can=0;
	contar(n,1,2,3);
	if(invalido){
		printf("No\n");
	}else{
		LL total=(1LL<<((LL)n))-1;
		printf("%lld\n",total-can);
	}
	
}