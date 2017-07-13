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
#define MAXN 1010
#define LOG 21

char cad[MAXN];

char resta(char c,char k){
	int menos=k-'A';
	if(c-menos>='A'){
		return (char)(c-menos);
	}else{
		int quitar=(int)(c-'A')+1;
		menos-=quitar;
		c='Z';
		return (char)(c-menos);
	}
}

int main(){
	string word,key;
	scanf("%s",cad);
	word=cad;
	scanf("%s",cad);
	key=cad;
	int n,m;
	n=word.size();
	m=key.size();
	string descifrado="";
	int j=m;
	for(int i=0;i<n;i++){
		char c=resta(word[i],cad[i]);
		descifrado=descifrado+c;
		cad[j]=c;
		j++;
	}
	printf("%s\n",descifrado.c_str());
}