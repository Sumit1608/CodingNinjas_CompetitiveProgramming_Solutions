#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
int const mod = 1000000007;


//Application of Kruskal's Algorihtm
// Find the MST of the graph but if the weight of the edges/road is greater than the 
// cost of airport, then don't include that road in mst, we can build another airport
// Now, the number of airports can be determined from the parents array, the no of 
// different parents' value denotes the no of components of graph (= no of airport).
class Edges{
	public:
		int src;
		int dest;
		int weight;
};

class compare{
	public:
		bool operator()(Edges const &a, Edges const &b){
			return a.weight < b.weight;
		}
};

int findParent(int *parent, int node){
	if(parent[node] == node){
		return node;
	}
	return findParent(parent, parent[node]);
}

int getOuput(Edges *arr, int n, int m, int *parent, int airport){
	int output = 0;
	for(int i=0; i<m; i++){
		Edges e = arr[i];
		
		int parentSrc = findParent(parent, e.src);
		int parentDest = findParent(parent, e.dest);
		if(parentSrc != parentDest && e.weight < airport){
                output += e.weight;
                parent[parentSrc] = parentDest;
            }
	}
	return output;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    int Case =1;
    while(t--){
        int n, m, airport;
        cin >> n >> m >> airport;
        
        Edges *arr = new Edges[n];
        for(int i=0; i<m; i++){
        	Edges a;
        	cin >> a.src >> a.dest >> a.weight;
        	a.src--;
        	a.dest--;
        	arr[i] = a;
		}
		sort(arr, arr+m, compare());
		int *parent = new int[n];
		for(int i=0; i<n; i++){
			parent[i] =i;
		}
		int count =0;
		int output = getOuput(arr, n, m, parent, airport);
		
		for(int i=0; i<n; i++){
			if(parent[i]==i){
				count++;
				output += airport;
			}
		}
		cout << "Case #" << Case << ": " << output << " " << count << endl;
		Case++;
    }

    return 0;
}


