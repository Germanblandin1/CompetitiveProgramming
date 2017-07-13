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
#define MAXN 26
int n,m;
LL dp[MAXN][MAXN];


int main(){
	for(int i=1;i<=25;i++){
		dp[2][i]=i;
	}
	for(int i=3;i<=25;i++){
		for(int j=1;j<=25;j++){
			dp[i][j]=dp[i-1][j]+dp[i][j-1];
		}
	}
	
	
	int t;
	ileer(t);
	For(c,t){
		i2leer(n,m);
		printf("%lld\n",dp[n][m]);
	}
}