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
#define MAXN 3000
#define LOG 21


int f[MAXN];

void precarga(int n){
	
	for(int k=2;k<=n;k++){
		f[k]=1;
		for(int i=2;i*i<=k;i++){
			if(k%i==0){
				f[k]+=i;
				if(k/i!=i)
					f[k]+=k/i;
			}
		}
	}
}

int main(){
	
	
	precarga(1000);
	int t;
	ileer(t);
	
	For(c,t){
		int n;
		ileer(n);
		if(f[n]<n){
			printf("deficient\n");
		}else if(f[n]==n){
			printf("perfect\n");
		}else{
			printf("abundant\n");
		}
		
	}
	
}