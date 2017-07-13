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

bool restos[100001];
char cad[100001];
string calcular(int n){
	int j=0;
	cad[0]='0';
	cad[1]='.';
	j=2;
	llenar(restos,false);
	int r=1;
	while(!restos[r]){
		restos[r]=true;
		int can=0;
		while(r<n){
			r*=10;
			can++;
		}
		for(int i=0;i<can-1;i++) cad[j++]='0';
		int div=r/n;
		int mod=r%n;
		char c=(char)(div+'0');
		cad[j++]=c;
		r=mod;
	}
	cad[j]='\0';
	string res=cad;
	return res;
	
}

string mapa[100001];
int main(){
	for(int i=0;i<100001;i++) mapa[i]="";
	int t;
	ileer(t);
	
	For(c,t){
		int n;
		ileer(n);
		string res;
		if(mapa[n].find(".")){
			res=calcular(n);
			mapa[n]=res;
		}else 
			res=mapa[n];
		printf("%s\n",res.c_str());
	}
}