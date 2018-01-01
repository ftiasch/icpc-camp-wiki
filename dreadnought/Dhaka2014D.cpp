#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<cstring>
#include<iostream>
#include<ctype.h>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<cmath>
#include<bitset>
#include<iomanip>
#include<complex>
#include<utility>

#define REP_0(i,n) for(int i=0;i<(n);++i)
#define REP_1(i,n) for(int i=1;i<=(n);++i)

using namespace std;

typedef long long LL;
typedef long double LD;
typedef double DB;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef pair<int,PII> PIII;
typedef pair<LD,int> PLDI;
typedef vector<PII> VII;

template<class T>
void UpdateMin(T &x,T y){
	if(y<x)
	{
		x=y;
	}
}

struct EDGE{
	int T,U,V;EDGE *Nxt,*Op;
	void init(const int S,const int T,const int U,const int V,EDGE *Op);
}*V[300],E[50000],*PE;

void EDGE::init(const int S,const int T,const int U,const int V,EDGE *Op){
	this->T=T;
	this->U=U;
	this->V=V;
	this->Op=Op;
	this->Nxt=::V[S];
	::V[S]=this;
}

inline void addedge(int S,int T,int U,int V){
	PE->init(S,T,U,V,PE+1);
	++PE;
	PE->init(T,S,0,-V,PE-1);
	++PE;
}

const int inf=0x3f3f3f3f;

int Test;
int N,M,L,U;
int Dist[300];
bool in[300];

int S,T;
int mincost;

int QH,QT;
int Q[3003];

int cnt[3004];

int G[301][301];

int uc[301],ur[301];

inline bool modlabel(){
	for(int i=0;i<=T;++i) Dist[i]=inf,in[i]=0,cnt[i]=0;
	Dist[T]=0;
	QH=QT=-1;
	Q[++QT]=T;
	while(QH++!=QT){
		if(QH==2000) QH=0;
		int x=Q[QH];
		in[x]=0;
		for(EDGE *ii=V[x];ii;ii=ii->Nxt) if(ii->Op->U){
			if(ii->Op->V+Dist[x]<Dist[ii->T]){
				Dist[ii->T]=ii->Op->V+Dist[x];
				if(!in[ii->T]){
					in[ii->T]=1;
					if(++QT==2000) QT=0;
					Q[QT]=ii->T;
					cnt[ii->T]=cnt[x]+1;
					if(cnt[ii->T]>T+2){
						mincost=inf;
						return false;
					}
				}
			}
		}
	}
	return Dist[S]!=inf;
}

int aug(int x,int limit){
	if(x==T){
		mincost+=limit*Dist[S];
		return limit;
	}
	int kk,ll=limit;
	in[x]=1;
	for(EDGE *ii=V[x];ii;ii=ii->Nxt) if(ii->U&&!in[ii->T]&&ii->V+Dist[ii->T]==Dist[x]){
		kk=aug(ii->T,min(ii->U,ll));
		ll-=kk;
		ii->U-=kk;
		ii->Op->U+=kk;
		if(!ll) return in[x]=0,limit;
	}
	return limit-ll;
}

int main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	scanf("%d",&Test);
	REP_1(tt,Test){
		scanf("%d%d%d%d",&N,&M,&L,&U);
		memset(V,0,sizeof(V));
		PE=E;
		S=N+M,T=S+1;
		mincost=0;
		long long presum=0;
		REP_0(i,N) ur[i]=M;
		REP_0(i,M) uc[i]=N;
		REP_0(i,N) REP_0(j,M){
			static char s[100];
			scanf("%s",s);
			if(s[0]!='X'){
				int x;
				sscanf(s,"%d",&x);
				addedge(N+j,i,inf,U-x);
				addedge(i,N+j,inf,x-L);
				mincost+=x;
				presum+=x;
			}
			else --ur[i],--uc[j];
		}
		REP_0(i,M) addedge(S,N+i,uc[i],0);
		REP_0(i,N) addedge(i,T,ur[i],0);
		while(modlabel()){
			do{
				memset(in,0,sizeof(in[0])* (T + 10));
			}while(aug(S,inf));
		}
		if(mincost==inf){
			printf("Case %d: Impossible\n",tt);
			continue;
		}
		printf("Case %d: %d\n",tt,mincost);
		memset(G,63,sizeof(G));
		REP_0(i,N+M){
			G[i][i]=0;
			for(EDGE *ii=V[i];ii;ii=ii->Nxt) if(ii->Op>ii){
				UpdateMin(G[i][ii->T],ii->V);
				if(ii->U!=inf){
					UpdateMin(G[ii->T][i],-ii->V);
				}
			}
		}
		memset(Dist,0,sizeof(Dist));
		QH=QT=-1;
		memset(in,0,sizeof(in));
		REP_0(i,N+M) Q[++QT]=i;
		while(QH++!=QT){
			if(QH==2000) QH=0;
			int x=Q[QH];
			in[x]=0;
			REP_0(i,N+M){
				if(G[x][i]+Dist[x]<Dist[i]){
					Dist[i]=G[x][i]+Dist[x];
					if(!in[i]){
						in[i]=1;
						if(++QT==2000) QT=0;
						Q[QT]=i;
					}
				}
			}
		}
		int minv=Dist[0];
		REP_0(i,N+M) UpdateMin(minv,Dist[i]);
		REP_0(i,N+M) assert(Dist[i]-minv>=0);
		REP_0(i,N) printf("%d%c",Dist[i]-minv,i==N-1?'\n':' ');
		REP_0(i,M) printf("%d%c",Dist[i+N]-minv,i==M-1?'\n':' ');
	}
	return 0;
}
