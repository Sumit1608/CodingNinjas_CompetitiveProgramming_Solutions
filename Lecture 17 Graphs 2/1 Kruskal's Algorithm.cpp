#include <bits/stdc++.h>
using namespace std;

// time comp => O(ElogE) + O(v*E)
// using union find algorihtm for detecting the cycle in graph
typedef long long int ll;
int const mod = 1000000007;

class Edge{
	public:
		int src;
		int dest;
		int weight;
};

bool mycompare(Edge e1, Edge e2){
	return e1.weight < e2.weight;
}

// function to the return the topmost parent of a vertex
int getParent(int v, int *parent){
	if(parent[v] == v){
		return v;
	}
	return getParent(parent[v], parent);
}

Edge* kruskals(Edge *edges, int n, int E){
	// sort the edges array in increasing order wrt to weight of th edges
	sort(edges, edges+E, mycompare);
	
	Edge *output = new Edge[n-1];
	int *parent = new int[n];
	for(int i=0; i<n; i++){
		parent[i] = i;
	}
	
	int count =0;
	int i=0;
	while(count < (n-1)){
		// check the topmost parent of vertices v1 and v2
		Edge currentEdge = edges[i];
		int srcParent = getParent(currentEdge.src, parent);
		int destParent = getParent(currentEdge.dest, parent);
		// if topmost parents are not same, then take the edge in MST
		if(srcParent != destParent){
			output[count] = currentEdge;
			count++;
			parent[srcParent] = destParent;
		}
		i++;
	}
	return output;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // no of vertices and no of edges present in the graph
    int n, E;
    cin >> n >> E;
    // array to store the edges with their weight
    Edge *edges = new Edge[E];
    
    for(int i=0; i<E; i++){
    	int s, d, w;
    	cin >> s >> d >> w;
    	edges[i].src = s;
		edges[i].dest = d;
		edges[i].weight = w;
	}
	
	Edge *output = kruskals(edges, n, E);
    for(int i=0; i<n-1; i++){
    	if(output[i].src < output[i].dest){
    		cout << output[i].src <<" "<< output[i].dest <<" "<<output[i].weight << endl;
		} else{
			cout << output[i].dest <<" "<< output[i].src <<" "<<output[i].weight << endl;
		}
	}
    return 0;
}

