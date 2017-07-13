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
#define MAXN 100001
#define LOG 21

int arr[MAXN];
int mapa[1000002];
int main(){
	int t;
	ileer(t);
	For(c,t){
		int n;
		ileer(n);
		For(i,n){
			ileer(arr[i]);
		}
		llenar(mapa,0);
		int ant=0;
		int can=0;
		int maxi=0;
		for(int i=0;i<n;i++){
			mapa[arr[i]]++;
			can++;
			while(mapa[arr[i]]>1){
				mapa[arr[ant]]--;
				ant++;
				can--;
			}
			maxi=max(can,maxi);
		}
		printf("%d\n",maxi);
		
		
	}
}