#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
int const mod = 1000000007;

/*
A Bipartite Graph is a graph whose vertices can be divided into two independent sets, 
U and V such that every edge (u, v) either connects a vertex from U to V or a vertex from 
V to U. In other words, for every edge (u, v), either u belongs to U and v to V, or u 
belongs to V and v to U. We can also say that there is no edge that connects vertices of same set.
A bipartite graph is possible if the graph coloring is possible using two colors such 
that vertices in a set are colored with the same color. Note that it is possible to 
color a cycle graph with even cycle using two colors.
Note: A cyclic graph with odd no of edges can't be a bipartite. 
*/
// time comp => O(V+E)

bool bipartite(vector<int> *edges, int n){
	if(n == 0)
		return true;
	// We maintain 2 sets for colors
	unordered_set<int> sets[2];
	// Push the neighbors of the current node in pending list so that we can assign their neighbors color
	vector<int> pending;
	// let the 0th vertex have the color zeroth
	set[0].insert(0);
	pending.push_back(0);
	
	while(pending.size() > 0){
		int current = pending.back();
		pending.pop_back();
		// find the color set of the current node
		int currentSet = sets[0].count(current) > 0 ? 0 : 1;
		// then look for its neighbor
		for(int i=0; i<edges[current].size(); i++){
			int neighbor = edges[current][i];
			// if the neighbor haven't been encountered yet, then put them in the differnet
			// color set as of the current node
			if(sets[0].count(neighbor) == 0 && sets[1].count(neighbor) == 0){
				sets[1 - currentSet].insert(neighbor);
				pending.push_back(neighbor);
			}
			// else if the neighbor is already present in the same set, then the graph can't eb bipartite
			else if(sets[currentSet].count(neighbor) > 0){
				return false;
			}
			// else the neighbor must be present in the other color set than current node
		}
	}
	
	return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(true){
    	int n;
    	cin >>n;
    	if(n == 0){
    		break;
		}
		// store the edges in adjacency matrix
		vector<int> *edges = new vector<int>[n];
		int m; 
		cin >>m;
		for(int i=0; i<m; i++){
			int j, k;
			cin >> j >> k;
			edges[j].push_back(k);
			edges[k].push_back(j);
		}
		
		bool ans = bipartite(edges, n);
		delete []edges;
		// If the graph is bipartite then it is bicolorable otherwise not
		if(ans)
			cout << "BICOLORABLE" << endl;
		else
			cout << "NOT BICOLORABLE" << endl;
    }

    return 0;
}


