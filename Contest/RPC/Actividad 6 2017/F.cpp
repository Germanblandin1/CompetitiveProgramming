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
#define MAXN 4001
#define LOG 21
int n,m;
char cad[200];
//   INPUT: w[i][j] = edge between row node i and column node j
//   OUTPUT: mr[i] = assignment for row node i, -1 if unassigned
//           mc[j] = assignment for column node j, -1 if unassigned
//           function returns number of matches made
int N,M; //   N:tam lado izquier, M: tam lado derecho

int mr[MAXN];
int mc[MAXN];
bool seen[MAXN];


bool FindMatch(int i,bool w[][MAXN]) {
  for (int j = 0; j < M; j++) {
    if (w[i][j] && !seen[j]) {
      seen[j] = true;
      if (mc[j] < 0 || FindMatch(mc[j],w)) {
        mr[i] = j;
        mc[j] = i;
        return true;
      }
    }
  }
  return false;
}

int BipartiteMatching(bool w[][MAXN]) {
	for(int i=0;i<N;i++) mr[i]=-1;
	for(int i=0;i<M;i++) mc[i]=-1;
	int ct = 0;
	for (int i = 0; i <N; i++) {
		llenar(seen,false);
		if (FindMatch(i,w)) ct++;
	}
	return ct;
}
bool w[MAXN][MAXN];
bool w2[MAXN][MAXN];
string rmap[MAXN];

int main(){
	int t;
	ileer(t);
	For(c,t){
		map<string,int> dulces;
		i2leer(n,m);
		N=n*2;
		M=m;
		For(i,n){
			//cout<<"puta"<<endl;
			scanf("%s",cad);
			string g=cad;
			dulces[g]=i;
			rmap[i]=g;
		}
		llenar(w,false);
		For(i,m){
			int a;
			ileer(a);
			For(j,a){
				int tipo,dul;
				scanf("%d %s",&tipo,cad);
				string g=cad;
				dul=dulces[g];
				if(tipo==1) dul+=n;
				if(tipo==2)
					w[dul][i]=true;
				w2[dul][i]=true;
			}
		}
		int can=BipartiteMatching(w);
		int can2=BipartiteMatching(w2);
		cout<<can<<" "<<can2<<endl;
		if(can==m) printf("0\n");
		else{
			bool posible=true;
			if(can2<m) posible=false;
			for(int i=0;i<n;i++){
				if(mr[i]!=-1 && mr[i+n]!=-1) posible=false;
			}
			if(!posible )printf("Impossible\n");
			else{
				vector<string> sol;
				for(int i=0;i<n;i++){
					if(mr[i+n]!=-1) sol.PB(rmap[i]);
				}
				sort(sol.begin(),sol.end());
				printf("%d\n",sol.size());
				for(int i=0;i<sol.size();i++){
					printf("%s\n",sol[i].c_str());
				}
			}
		}
		

	}
}