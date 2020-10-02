#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back

#define MAXSIZE 100001

vvi graph(MAXSIZE);	//adjacency list
vector<bool> visited(MAXSIZE, 0);	//'visited' vector

void dfs(int src) {
	visited[src] = 1;		//make the node visited in the 'visited' vector
	cout << src << endl;	//print the node
	for (auto nbr : graph[src]) {		//traverse the neighbours of the current node
		if (!visited[nbr])		//if neighbour is not visited
			dfs(nbr);			//then recursively call dfs() on the neighbour
	}
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

	cout << "DFS Traversal\n";
	dfs(1);	//calling dfs() from node '1'
	return 0;
}