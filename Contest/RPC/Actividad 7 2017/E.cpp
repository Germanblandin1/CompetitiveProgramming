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
#define MAXN 110
#define LOG 21

char cad[MAXN];


int main(){
	scanf("%s",cad);
	int n=strlen(cad);
	string original=cad;
	int mini=INF;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			int m=j-i+1;
			int costo=m+n;
			string busca="";
			busca.resize(m);
			for(int k=i;k<=j;k++){
				busca[k-i]=cad[k];
			}
			int k=0;
			int veces=0;
			while(k<n){
				int pos=original.find(busca,k);
				if(pos!=-1){
					veces++;
					k=pos+m;
				}else{
					k=n;
				}
				
			}
			costo-=veces*m;
			costo+=veces;
			mini=min(costo,mini);	
		}
	}
	printf("%d\n",min(mini,n));
	
	
}