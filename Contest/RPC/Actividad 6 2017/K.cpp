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

char cad[10];
int main(){
	int t;
	ileer(t);
	For(c,t){
		int n;
		ileer(n);
		double suma=0;
		double lado[3];
		lado[0]=lado[1]=0;
		int can=0;
		For(i,n){
			int l;
			scanf("%s %d",cad,&l);
			if(cad[0]=='C'){
				if(can==1){
					lado[0]+=l;
				}else if(can==2){
					lado[1]+=l;
				}
				can++;
				suma+=l*l;
			}
			if(cad[0]=='S') suma+=l*l;
			else if(cad[0]=='T') suma+=(sqrt(3)*l*l)/4.0;
			if(can<=2) lado[can-1]+=l;
		}
		double area=lado[0]*lado[1]-suma;
		printf("%.4lf\n",area);
	}
}