#include<stdio.h>
#include<stdlib.h>
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

#define X first
#define Y second
#define PB push_back
#define MP make_pair

using namespace std;

typedef long long LL;

template<class T>
T Gcd(T x,T y){
	if(y==0)return x;
	T z;
	while(z=x%y){
		x=y,y=z;
	}
	return y;
}

const int MOD=998244353;
const int MAXV=2333333;

struct treeNode{
	int len;
	long long sum;
	long long sum2;
	int v;
	treeNode():len(0),sum(0),sum2(0),v(0){}
	void clear(){sum=sum2=v=0;}
	void set(int v,int sum){this->v=v,this->sum=this->sum2=sum;}
}lt[270001];

int n;
int a[270001];


struct EDGE{
	long long T;EDGE *Nxt;
	void init(const int S,const long long T);
}E[MAXV+10],*V[MAXV+10],*PE;

void EDGE::init(const int S,const long long T){
	this->T=T;
	if(V[S]){
		this->Nxt=V[S]->Nxt;
		V[S]->Nxt=this;
		V[S]=this;
	}
	else{
		this->Nxt=V[S]=this;
	}
}

void buildTree(int n,int l,int r){
	lt[n].len=r-l+1;
	if(l==r){
		return;
	}
	int mid=(l+r)>>1;
	buildTree(n*2,l,mid);
	buildTree(n*2+1,mid+1,r);
}

inline void unionNode(treeNode &a,treeNode &b,treeNode &c,bool lens=false){
	if(a.v>b.v){
		c.v=a.v;
		c.sum2=a.sum2;
		c.sum=a.sum;
	}
	else if(b.v>a.v){
		c.v=b.v;
		c.sum2=b.sum2;
		c.sum=b.sum;
	}
	else{
		c.v=a.v;
		c.sum2=a.sum2+a.sum*b.len+b.sum2;
		if(c.sum2>=MOD) c.sum2%=MOD;
		c.sum=a.sum+b.sum;
		if(c.sum>=MOD) c.sum-=MOD;
	}
	if(lens){
		c.len=a.len+b.len;
	}
}

const int toBot=131072;

inline void change(int pos,int v,int sum){
	++pos;
	pos+=toBot;
	lt[pos].set(v,sum);
	while(pos!=1){
		int nxt=pos>>1;
		if(lt[pos].v>=lt[nxt].v) unionNode(lt[nxt<<1],lt[(nxt<<1)|1],lt[nxt]);
		else break;
		pos=nxt;
	}
}

inline pair<pair<long long,long long>,int> getsum(int l,int r){
	treeNode left,right;
	++l,++r;
	l+=toBot-1,r+=toBot+1;
	while(l^r^1){
		if(~l&1) unionNode(left,lt[l^1],left,true);
		if(r&1) unionNode(lt[r^1],right,right,true);
		l>>=1,r>>=1;
	}
	unionNode(left,right,left);
	return make_pair(make_pair(left.sum,left.sum2),left.v);
}

inline void clear(int pos){
	++pos;
	pos+=toBot;
	while(pos){
		if(!lt[pos].v) break;
		lt[pos].clear();
		pos>>=1;
	}
}

vector<pair<pair<int,int>,int> > GCDS;
vector<int> TD;

const LL MULNUM=1000000LL;

int main(){
	buildTree(1,0,131071);
	while(scanf("%d",&n)==1){
		for(int i=1;i<=n;++i) scanf("%d",a+i);
		TD.clear();
		GCDS.clear();
		PE=E;
		for(int i=1;i<=n;++i){
			for(int j=0;j<int(GCDS.size());++j){
				if(a[i]%GCDS[j].Y){
					GCDS[j].Y=Gcd(a[i],GCDS[j].Y);
				}
			}
			GCDS.PB(MP(MP(i,i),a[i]));
			{
				int tmp=0;
				for(int j=1;j<int(GCDS.size());++j){
					if(GCDS[j].Y==GCDS[tmp].Y){
						GCDS[tmp].X.Y=GCDS[j].X.Y;
					}
					else{
						GCDS[++tmp]=GCDS[j];
					}
				}
				GCDS.resize(tmp+1);
			}
			for(int j=0;j<int(GCDS.size());++j){
				if(!V[GCDS[j].Y]) TD.PB(GCDS[j].Y);
				PE++->init(GCDS[j].Y,(GCDS[j].X.X*MULNUM+GCDS[j].X.Y)*MULNUM+i);
			}
		}
		int ans0=0,ans1=0;
		for(int a=0;a<int(TD.size());++a){
			int num=TD[a];
			change(0,1,1);
			EDGE *st=V[num]->Nxt;
			V[num]->Nxt=0;
			V[num]=0;
			for(EDGE *i=st;i;i=i->Nxt){
				int x=i->T/MULNUM/MULNUM,y=i->T/MULNUM%MULNUM,z=i->T%MULNUM;
				long long add=0;
				int nv=0;
				pair<pair<long long,long long>,int> tmp;
				if(x!=y){
					tmp=getsum(x,y-1);
					add=tmp.X.Y;
					nv=tmp.Y;
				}
				tmp=getsum(0,x-1);
				if(nv<tmp.Y){
					nv=tmp.Y;
					add=0;
				}
				if(nv==tmp.Y){
					add+=tmp.X.X*(y-x+1);
					if(add>=MOD) add%=MOD;
				}
				change(z,nv+1,add);
				if(nv>ans0) ans0=nv,ans1=0;
				if(nv==ans0){
					ans1+=add;
					if(ans1>=MOD) ans1-=MOD;
				}
			}
			for(EDGE *i=st;i;i=i->Nxt){
				clear(i->T%MULNUM);
			}
			clear(0);
		}
		printf("%d %d\n",ans0,ans1);
	}
	return 0;
}
