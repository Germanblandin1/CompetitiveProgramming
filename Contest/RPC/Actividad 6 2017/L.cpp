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

char cad[2000];

int main(){
	int res[5];
	res[0]=76;
	res[1]=16;
	res[2]=56;
	res[3]=96;
	res[4]=36;
	int t;
	ileer(t);
	For(c,t){
		scanf("%s",cad);
		int tam=strlen(cad);
		if(tam==1 && cad[0]=='0') printf("1\n");
		else if(tam==1 && cad[0]=='1') printf("66\n");
		else{
			int val=cad[tam-1]-'0';
			val=val%5;
			printf("%d\n",res[val]);
		}
		
	}
}