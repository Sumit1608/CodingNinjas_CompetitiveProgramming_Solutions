#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
int const mod = 1000000007;

// time comp => O(v^2)
// this can be reduced with teh use of adjacency list and priority queue
int getMinVertex(vector<bool> &visited, vector<int> &weight, int v){
	int ans = -1;
	for(int i=0; i<v; i++){
		if(!visited[i] && (ans == -1 || weight[ans] > weight[i])){
			ans = i;
		}
	}
	return ans;
}

void prims(vector<vector<int> > &graph, int v){
	vector<int> parent(v);
	vector<int> weight(v, INT_MAX);
	vector<bool> visited(v, false);
	
	parent[0] = -1;
	weight[0] = 0;
	
	for(int i=0; i<v-1; i++){
		// get unvisited vertex with minimum weight
		int minVertex = getMinVertex(visited, weight, v);
		visited[minVertex] = true;
		
		// Explore all the neightbours of minimum vertex and update parent and weight array acc to that
		for(int j=0; j < v; j++){
			int temp = graph[minVertex][j];
			if(temp != 0 && !visited[j] && weight[j] > temp){
				weight[j] = temp;
				parent[j] = minVertex;
			}
		}	
	}
	
	for(int i=1; i<v; i++)
		cout << min(i,parent[i]) <<" " << max(i,parent[i]) << " " << weight[i] << endl;
	
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int v, e;
    cin >> v >> e;
    vector<vector<int> > graph(v, vector<int>(v, 0));
    for(int i=0; i<e; i++){
    	int f, s, weight;
    	cin >> f >> s >> weight;
    	graph[f][s] = weight;
    	graph[s][f] = weight;
	}
	prims(graph, v);
	
    return 0;
}




