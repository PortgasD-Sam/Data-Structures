#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back

#define MAXSIZE 100001

vvi graph(MAXSIZE);	//adjacency list
vector<bool> visited(MAXSIZE, 0);	//'visited' vector
vector<bool> color(MAXSIZE, 0);		//'color' vector

bool dfs_bipartite(int src, int c) {
	visited[src] = 1;		//make the node visited in the 'visited' vector
	color[src] = c;
	for (auto nbr : graph[src]) {		//traverse the neighbours of the current node
		if (!visited[nbr]) {			//If neighbour is not visited
			if (dfs_bipartite(nbr, c ^ 1) == false)	//call dfs on it and change the color
				return false;
		}
		else if (color[src] == color[nbr])	//check if color of source and neighbour are same
			return false;
	}
	return true;
}

int main() {
	// n-> no. of nodes
	// m-> no. of edges
	int n{}, m{};
	cin >> n >> m;

	//Undirected edges are recorded in the adjacency list
	for (int i = 0; i < m; i++) {
		int a{}, b{};
		cin >> a >> b;
		graph[a].pb(b);	//adding 'b' in a's adjacency list
		graph[b].pb(a);	//adding 'a' in b's adjacency list
	}

	cout << "Is the given the given graph BIPARTITE?\n";
	cout << (dfs_bipartite(1, 0) ? "YES\n" : "NO\n");
	return 0;
}