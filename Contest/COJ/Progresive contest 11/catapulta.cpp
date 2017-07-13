#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define DINF 1e10
#define EPS 1e-3
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


int main(){
	int x1,x2,y1,y2,v;
	while(scanf("%d %d %d %d %d",&x1,&y1,&x2,&y2,&v)!=EOF){
		bool sepuede=false;
		for(int i=0;i<=9000;i++){
			double grado=i/100.0+0.00000000001;
			double rgrado=(grado*PII)/180.0;
			double t1=(double)(x2-x1)/(v*cos(rgrado));
			

			double a,b,c;
			a=(-9.8)/2.0;
			b=v*sin(rgrado);
			double auxy=a*t1*t1+b*t1+y1;
			cout<<grado<<" "<<auxy<<endl;
			if(fabs(auxy-y2)<EPS){
				printf("%.2lf\n",grado);
				sepuede=true;
				break;
			}
		}
		if(!sepuede) printf("Impossible\n");
	}
}