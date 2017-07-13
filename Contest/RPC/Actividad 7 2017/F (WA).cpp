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
int valaux[MAXN];

int gcd(int a,int b){
	if(b==0) return a;
	if(a==0) return b;
	return gcd(b,a%b);
}

int matriz[MAXN][MAXN];
bool marca[MAXN][MAXN];
int queda[MAXN][MAXN];
int f(int i,int j){
	return gcd(val[i],val[j]);
}
int dp(int i,int j){
	if(j-i==1) return f(i,j);
	if(j-i==2) return 2*min(min(f(i+1,j),f(i,j-1)),f(i,j));
	int &mejor=matriz[i][j];
	if(marca[i][j]) return mejor;
	marca[i][j]=true;
	mejor=INF;
	
	mejor=min(dp(i,j-1)+f(i,j-1),dp(i+1,j)+f(i+1,j));

	return mejor;
	
}


int main(){
	while(ileer(n),n){
		For(i,n){
			ileer(val[i]);
			valaux[i]=val[i];
		}
		int k=0;
		int res=INF;
		while(k<n){
			for(int i=0;i<n;i++){
				val[(i+k)%n]=valaux[i];
			}
			llenar(marca,false);
			res=min(res,dp(0,n-1));
			k++;
		}
		printf("%d\n",res);
	}
}