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
int n,m;
char mapa[MAXN][MAXN];
int cant[2][MAXN][MAXN];
int cantI[2];
int movx[]={1,-1,0,0};
int movy[]={0,0,1,-1};

bool rango(int x,int y){
	if(x>=0 && x<n && y>=0 && y<m) return true;
	return false;
}

bool interseccion(int i,int j){
	if(!rango(i-1,j-1) || !rango(i+1,j+1)) return false;
	//cout<<"paso el rango"<<endl;
	if((mapa[i][j]=='X' || mapa[i][j]=='0') && (mapa[i-1][j]=='X' || mapa[i-1][j]=='0') && (mapa[i+1][j]=='X' || mapa[i+1][j]=='0') && (mapa[i][j-1]=='X' || mapa[i][j-1]=='0') && (mapa[i][j+1]=='X' || mapa[i][j+1]=='0')  &&mapa[i-1][j-1]=='.' &&mapa[i-1][j+1]=='.' &&mapa[i+1][j+1]=='.' &&mapa[i+1][j-1]=='.')
		return true;
	return false;
}

void rellenarP(int x,int y,char c){
	mapa[x][y]=c;
	for(int k=0;k<4;k++){
		int aux=x+movx[k];
		int auy=y+movy[k];
		if(rango(aux,auy)){
			if(mapa[aux][auy]=='.'){
				rellenarP(aux,auy,c);
			}
		}
	}
}

void marcarXA(int x,int y,char c,int dir){
	
	if(interseccion(x,y)){
		//cout<<"entro"<<endl;
		mapa[x][y]='P';
		marcarXA(x+movx[dir],y+movy[dir],c,dir);	
		return;
	}
	mapa[x][y]=c;
	for(int k=0;k<4;k++){
		int aux=x+movx[k];
		int auy=y+movy[k];
		if(rango(aux,auy)){
			if(mapa[aux][auy]=='X'){
				marcarXA(aux,auy,c,k);
			}
		}
	}
}

void contarP(int x,int y,int t){
	if(mapa[x][y]=='.'){
		cant[t][x][y]++;
		cantI[t]++;
	}else{
		cant[t][x][y]=2;
	}
	
	for(int k=0;k<4;k++){
		int aux=x+movx[k];
		int auy=y+movy[k];
		if(rango(aux,auy)){
			
			char contra= t==0?'1':'0';
			if((mapa[aux][auy]=='.' || mapa[aux][auy]==contra) && cant[t][aux][auy]==0){
				contarP(aux,auy,t);
			}
		}
	}
}

int main(){
	llenar(cant,0);
	i2leer(n,m);
	For(i,n){
		scanf("%s",mapa[i]);
	}

	//buscamos la A
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(mapa[i][j]=='A'){
				marcarXA(i,j,'0',-1);
			}
		}
	}
	
	//buscamos la B
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(mapa[i][j]=='X' || mapa[i][j]=='B'){
				mapa[i][j]='1';
			}
		}
	}
	
	//marcamos el exterior como invalidos -
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(i==0 || j==0 || i==n-1 || j==m-1){
				if(mapa[i][j]=='.') rellenarP(i,j,'-');
			}
		}
	}
	
	int empezo=0;
	int contrario=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(!empezo){
				if(mapa[i][j]=='.'){
					if(mapa[i][j-1]=='0'){
						contarP(i,j,0);
						empezo++;
						contrario=1;
					}else if(mapa[i][j-1]=='1'){
						contarP(i,j,1);
						empezo++;
						contrario=0;
					}
				}
			}else if(empezo==1){
				if(mapa[i][j]=='.'){
					if(cant[(contrario+1)%2][i][j]==0){
						empezo++;
						contarP(i,j,contrario);
					}
				}
				
			}
			
		}
	}
	int ceros=cantI[0];
	int unos=cantI[1];
	int ambos=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(cant[0][i][j]==1 && cant[1][i][j]==1) ambos++;
		}
	}
	
	printf("%d %d %d\n",ceros-ambos,unos-ambos,ambos);
	/*
	cout<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<cant[0][i][j];
		}
		cout<<endl;
	}
	cout<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<cant[1][i][j];
		}
		cout<<endl;
	}
	*/
	
	
}