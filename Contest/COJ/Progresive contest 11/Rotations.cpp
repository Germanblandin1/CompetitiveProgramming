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

int arr[40];
int main(){
	int t;
	ileer(t);
	For(c,t){
		LL n;
		scanf("%lld",&n);
		llenar(arr,0);
		bool sepuede=true;
		for(int i=0;i<=31 && sepuede;i++){
			int num=0;
			for(int j=0;j<5;j++){
				if(n&(1LL<<((i+j)%32))){
					num=num|(1<<j);
				}
			}
			arr[num]++;
			if(arr[num]>1) sepuede=false;
		}
		printf("%s\n",sepuede?"yes":"no");
	}
}