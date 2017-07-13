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
#define MAXN 1000001

int arr[MAXN];
int aux[MAXN];
LL inver;
void mergesort(int li,int ls){
	if(li+1==ls){
		return;
	}
	int mid=(li+ls)/2;
	mergesort(li,mid);
	mergesort(mid,ls);
	int i=li;
	int k=li;
	int j=mid;
	LL can=0;
	while(i<mid || j<ls){
		if(j==ls || (i<mid && arr[i]<=arr[j])){
			if(i<mid)inver+=can;
			aux[k++]=arr[i++];
		}else{
			if(i<mid && j<ls && arr[i]>arr[j]) can++;
			aux[k++]=arr[j++];
		} 
	}
	for(int i=li;i<ls;i++) arr[i]=aux[i];
	//printf("%d %d %d %d\n",li+1,ls,arr[li],arr[ls-1]);
}



int main(){
	int n;
	while(ileer(n),n){
		For(i,n) ileer(arr[i]);
		inver=0;
		mergesort(0,n);
		printf("%lld\n",inver);
		//For(i,n) printf("%d%s",arr[i],i==n-1?"\n":" ");
	}
}