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

int res[22];
int main(){
	
	for(int i=1;i<=21;i++){
		int n=i;
		double x=0;
		int j=1;
		int vez=0;
		while(x<n){
			x=x+1.0/(sqrt(j)+sqrt(j+1));
			j+=1;
			vez++;
		}
		res[i]=vez;
	}
	
	
	int t;
	ileer(t);
	int dif=0;
	int ant=0;
	For(c,t){
		int n;
		ileer(n);
		if(n<=21){
			printf("%d\n",res[n]);
		}else{
			int dif=n-21;
			LL res=483LL+43LL*dif+dif*(dif+1LL);
			printf("%lld\n",res);
		}

	}
}