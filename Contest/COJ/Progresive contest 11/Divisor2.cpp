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


int main(){
	int t;
	ileer(t);
	For(c,t){
		int n,k;
		i2leer(n,k);
		LL suma=0;
		for(int i=1;i*i<=n;i++){
			if(n%i==0){
				int div1=i;
				int div2=n/i;
				if(div1%k!=0) suma+=div1;
				if(div1!=div2 && div2%k!=0) suma+=div2;
			}
		}
		printf("%lld\n",suma);
	}
}