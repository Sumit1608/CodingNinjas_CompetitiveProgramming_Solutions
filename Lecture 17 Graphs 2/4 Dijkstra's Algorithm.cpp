#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
int const mod = 1000000007;

// time comp => O(v^2)
// this can be reduced with teh use of adjacency list and binary heap
int getMinVertex(vector<bool> &visited, vector<int> &distance, int v){
	int ans = -1;
	for(int i=0; i<v; i++){
		if(!visited[i] && (ans == -1 || distance[ans] > distance[i]) ){
			ans = i;
		}
	}
	return ans;
}

void dijkstra(vector<vector<int> > &graph, int v){
	vector<int> distance(v, INT_MAX);
	vector<bool> visited(v, false);
	
	distance[0] = 0;
	
	for(int i=0; i<v-1; i++){
		// get unvisited vertex with minimum distance
		int minVertex = getMinVertex(visited, distance, v);
		visited[minVertex] = true;
		
		// Explore all the neightbours of minimum vertex and update distance array acc to that
		for(int j=0; j < v; j++){
			int temp = graph[minVertex][j];
			if(temp != 0 && !visited[j])
				if(distance[j] > (temp + distance[minVertex]) )
					distance[j] = temp + distance[minVertex] ;
		}	
	}
	
	for(int i=0; i<v; i++)
		cout << i << " " << distance[i] << endl;	
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
	dijkstra(graph, v);
	
    return 0;
}




