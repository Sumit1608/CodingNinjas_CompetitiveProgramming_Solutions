#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
int const mod = 1000000007;

// time comp => Time Complexity: O(V + E) 
// We search the path using BFS, we mark the nodes that are connecte to the
// starting node, amd then the nodes which are connected to those node, if we encounter
// the ending node, we return ture, else false
bool hasPath(int **arr, int v, int sv, int ev, bool *visited){
	visited[sv] = true;
	queue<int> q;
	q.push(sv);
	while(!q.empty()){
		if(q.front() == ev){
			return true;
		}
		int currVertex = q.front();
		q.pop();
		for(int i=0; i<v; i++){
			if(i == currVertex || visited[i]){
				continue;
			}
			if(arr[currVertex][i] == 1){
				visited[i] = true;
				q.push(i);
			}
		}
	}
	return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int v, e;
    cin >> v>> e;
    int **arr = new int*[v];
	for(int i=0; i<v; i++){
		arr[i] = new int[v]();
	}
	
	while(e--){
		int a, b;
		cin >> a>>b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}
	
	bool *visited = new bool[v];
	for(int i=0; i<v; i++)
		visited[i] = false;
	int v1, v2;
	cin >> v1 >> v2;
    if( hasPath(arr, v, v1, v2, visited)){
    	cout << "true" << endl;
	} else{
		cout << "false" << endl;
	}
	
    return 0;
}


