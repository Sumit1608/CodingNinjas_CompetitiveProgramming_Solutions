#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
int const mod = 1000000007;

// sv is the starting vertex
void print(int** edges, int n, int sv, bool* visited){
  	cout << sv << endl;
  	visited[sv] = true;
  	for(int i=0; i<n; i++){
    	if(i==sv){
      		continue;
    	}
    	if(edges[sv][i]==1){
    	  	if(visited[i]){
        		continue;
      		}
			print(edges, n, i, visited);
    	}
  	}
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, e;
    // no of vertices and no of edges
    cin >> n >> e;
    // matrix which tells whether there is an edge between vertices V1 and V2
    int **edges = new int*[n];
    for(int i=0; i<n; i++){
    	edges[i] = new int[n];
    	for(int j=0; j<n; j++){
    		edges[i][j] = 0;
		}
	}
	
	for(int i=0; i<e; i++){
		int f, s;
		cin >> f >> s;
		edges[f][s] = 1;
		edges[s][f] = 1;
	}
	
	bool *visited = new bool[n];
	for(int i=0; i<n; i++){
		visited[i] = 0;
	}
    
    print(edges, n, 0, visited);
    
    return 0;
}


