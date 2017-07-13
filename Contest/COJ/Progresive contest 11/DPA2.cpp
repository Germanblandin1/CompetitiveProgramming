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

LL ABS(LL x){
	if(x < 0 ) return -x;
	return x;
}
LL mrandom(){
	LL x = ((LL)rand()) * ((LL)rand());
	return x;
}
LL my_random(LL a, LL b){
	LL dif = b - a + 1;
	return mrandom()%dif + a;
}
LL gcd(LL a, LL b){
	if(a==0LL) return b;
	if(b==0LL) return a;
	return gcd(b, a%b);
}
LL mulmod(LL a, LL b, LL m){
	LL x = 0LL, y = a%m;
	while(b > 0LL){
		if(b & 1LL) x = (x + y)%m;
		y = (y*2)%m;
		b>>=1LL;
	}
	return x%m;
}
LL fpow(LL a, LL e, LL m){
	LL x = 1, y = a;
	while(e > 0LL){
		if(e & 1LL) x = mulmod(x,y,m);
		y = mulmod(y,y,m);
		e>>=1LL;
	}
	return x%m;
}
bool primetest(LL n, int k){
	if(n==1LL) return false;
	if(n==2LL || n==3LL) return true;
	if(!(n & 1LL)) return false;
	LL r = 0, d = n-1;
	while(!(d & 1LL)){ r++; d/=2LL;}
	for(int i=0; i<k; i++){
		LL a = my_random(2LL, n-2);
		LL x = fpow(a, d, n);
		if(x==1LL || x==n-1LL) continue;
		bool compo = true;
		for(int i=0; i<r-1 && compo; i++){
			x = fpow(x, 2LL, n);
			if(x==1LL) return false;
			if(x==n-1LL){
				compo = false;
			}
		}
		if(compo) return false;
	}
	return true;
}
LL f(LL x, LL c, LL n){
	return (mulmod(x,x,n) + c)%n;
}
LL pollard_rho(LL n, LL c){
	LL i = 0LL;
	LL k=2LL;
	LL x = 2, y = 2;
	while(true){
		i++;
		x = f(x,c, n); 
		LL d = gcd(ABS(y-x), n);
		if(d>1) return d;
		if(i==k) y = x, k<<=1LL;	
	}
	return -1;
}
map<LL,int> pfactors;
void factorize(LL n){
	if(n==1LL) return;
	LL x = n;
	bool P = primetest(n, 3);
	for(LL i=2; x==n && !P; i++){
		x = pollard_rho(n, i);
	}
	
	if(x==n){
		pfactors[n]++;  
		return;
	}
	factorize(n/x); factorize(x);
	
}

vector<pair<LL,int> > factores; 
int N;
LL suma=0;
void divisores(LL cur,int i){
	if(i==N){
		//cout<<"sumo "<<cur<<endl;
		suma+=cur;
		return;
	}
	for(int j=0;j<=factores[i].S;j++){
		divisores(cur,i+1);
		cur*=factores[i].F;
	}
}



int main(){
	srand(546465);
	int t;
	ileer(t);
	
	For(c,t){
		LL n;
		scanf("%lld",&n);
		
		factorize(n);
		map<LL,int>::iterator it;
		
		for(it=pfactors.begin();it!=pfactors.end();it++){
			//cout<<it->F<<" "<<it->S<<endl;
			factores.PB(MK(it->F,it->S));
		}
		N=factores.size();
		suma=0LL;
		divisores(1,0);
		suma-=n;
		LL val=suma;
		if(val<n){
			printf("deficient\n");
		}else if(val==n){
			printf("perfect\n");
		}else{
			printf("abundant\n");
		}
		pfactors.clear();
		factores.clear();
	}
	
}