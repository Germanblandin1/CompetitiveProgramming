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
#define MAXN 500
#define LOG 21
int n;
int grafo[MAXN][MAXN];
int grafo2[MAXN][MAXN];
int floyd[MAXN][MAXN];
bool marca[MAXN];
int torres[MAXN];
int main(){
	int t;
	ileer(t);
	For(c,t){
		ileer(n);
		For(i,n){
			For(j,n){
				ileer(grafo[i][j]);
				grafo2[i][j]=INF;
				//floyd[i][j]=grafo[i][j];
			}
		}
		/*
		for(int k=0;k<n;k++){
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					floyd[i][j]=min(floyd[i][j],floyd[i][k]+floyd[k][j]);
				}
			}
		}
		
		cout<<"elfloyd"<<endl;
		for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					cout<<floyd[i][j]<<" ";
				}
				cout<<endl;
			}
		cout<<endl;
		*/
		for(int k=0;k<n;k++){
			ileer(torres[k]);
		}
		LL res=0;
		llenar(marca,false);
		for(int k=n-1;k>=0;k--){
			int x=torres[k];
			
			grafo2[x][x]=0;
			for(int i=0;i<n;i++){
				if(!marca[i]) continue;
				grafo2[i][x]=grafo[i][x];
				grafo2[x][i]=grafo[x][i];
			}
			marca[x]=true;
			for(int l=0;l<n;l++){
				if(!marca[l]) continue;
				for(int i=0;i<n;i++){
					if(!marca[i]) continue;
					grafo2[i][x]=min(grafo2[i][x],grafo2[i][l]+grafo2[l][x]);
					grafo2[x][i]=min(grafo2[x][i],grafo2[x][l]+grafo2[l][i]);
				}
			}
			
			for(int i=0;i<n;i++){
				if(!marca[i]) continue;
				for(int j=0;j<n;j++){
					if(!marca[j]) continue;
					grafo2[i][j]=min(grafo2[i][j],grafo2[i][x]+grafo2[x][j]);
				}
			}

			for(int i=0;i<n;i++){
				if(!marca[i]) continue;
				for(int j=0;j<n;j++){
					if(!marca[j]) continue;
					res+=(LL)grafo2[i][j];
				}
			}
			
			
		}
		

		
		printf("%lld\n",res);
	}
}