#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;
int t[2*N],d[N],n,h;

void apply(int p,int value)
{
	t[p]+=value;
	if(p<n) d[p]+=value;
}

void build(int p)
{
	while(p>1) p>>=1, t[p] = max(t[p<<1],t[p<<1|1]) + d[p];
}

void push(int p)
{
	for(int s=h;s>0;s--)
	{
		int i = p>>s;
		if(d[i]!=0)
		{
			apply(i<<1,d[i]);
			apply(i<<1|1,d[i]);
			d[i] = 0;
		}
	}
}

void modify(int l,int r,int value)
{
	l+=n;
	r+=n;
	int l0 = l;
	int r0 = r;
	for(;l < r;l>>=1,r>>=1)
	{
		if(l&1) apply(l++,value);
		if(r&1) apply(--r,value);
	}
	build(l0);
	build(r0 - 1);
}

int query(int l,int r)
{
	l+=n;
	r+=n;
	int resl,resr,res;
	resl = resr = INT_MIN;
	push(l);
	push(r - 1);
	for(;l < r;l>>=1,r>>=1)
	{
		if(l&1) resl = max(t[l++],resl);
		if(r&1) resr = max(t[--r],resr);
	}
	res = max(resl,resr);
	return res;
}

int main()
{
	scanf("%d",&n);
	h = sizeof(int) * 8 - __builtin_clz(n);
	for(int i=0;i<n;i++) scanf("%d",t + n + i);
	for(int i=2*n-1;i>0;i--) build(i);
	modify(13,14,8);
	int ans = query(6,14);
	printf("%d\n",ans);
	return 0;
}