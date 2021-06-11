#include <bits/stdc++.h>
using namespace std;

// time comp => O(ElogE) + O(Elogv)
// using UNion by Rank and Compression algorihtm for detecting the cycle in graph
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

// A structure to represent a subset for union-find
class subset {
public:
    int parent;
    int rank;
};
 
// A utility function to find set of an element i (uses path compression technique)
int getParent(subset subsets[], int i){
    // find root and make root as parent of i (path compression)
    if (subsets[i].parent != i)
        subsets[i].parent = getParent(subsets, subsets[i].parent);
    return subsets[i].parent;
}
 
// A function that does union of two sets of x and y (uses union by rank)
void Union(subset subsets[], int x, int y){
    int xroot = getParent(subsets, x);
    int yroot = getParent(subsets, y);
 
    // Attach smaller rank tree under root of high rank tree (Union by Rank)
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
 
    // If ranks are same, then make one as root and increment its rank by one
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

Edge* kruskals(Edge *edges, int n, int E){
	// sort the edges array in increasing order wrt to weight of th edges
	sort(edges, edges+E, mycompare);
	
	Edge *output = new Edge[n-1];
	subset *parent = new subset[n];
	for(int i=0; i<n; i++){
		parent[i].parent = i;
		parent[i].rank = 0;
	}
	
	int count =0;
	int i=0;
	while(count < (n-1)){
		// check the topmost parent of vertices v1 and v2
		Edge currentEdge = edges[i];
		int srcParent = getParent(parent, currentEdge.src);
		int destParent = getParent(parent, currentEdge.dest);
		// if topmost parents are not same, then take the edge in MST
		if(srcParent != destParent){
			output[count] = currentEdge;
			count++;
			Union(parent, srcParent, destParent);
//			parent[srcParent] = destParent;
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

