#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

#define MAXSIZE 1024
#define FORI(n) for(int i=0;i<n;i++)

vvi graph(MAXSIZE);
bool vis[MAXSIZE];
queue<int> q;

void bfs(int s)
{
	vis[s] = true;
	q.push(s);
	printf("%d ",s);
	while(!q.empty())
	{
		int front = q.front();
		q.pop();
		FORI(graph[front].size())
		{
			int child = graph[front][i];
			if(!vis[child])
			{
				vis[child] = true;
				q.push(child);
				printf("%d ",child);
			}
		}
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	memset(vis,false,sizeof(vis));
	FORI(n-1)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	printf("bfs traversal - ");
	bfs(1);
	return 0;
}