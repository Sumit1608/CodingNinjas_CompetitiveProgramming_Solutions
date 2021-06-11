#include<bits/stdc++.h>
using namespace std;

// use BFS/DFS traversal to mark the vertices that can be visited from a particualr vertex
// if all the vertex are visited, then the boolean array will contain true at every index
void isConnected(int** arr, int n, int starting_vertex, bool* visited){
	queue<int> q;
	q.push(starting_vertex);
	visited[starting_vertex] = true;
    
	while (!q.empty()){
		int current_element = q.front();
		for (int i = 1; i < n; i++){
			if (i == current_element)
				continue;
			if (visited[i])
				continue;
			if (arr[current_element][i] == 1){
				q.push(i);
				visited[i] = true;
			}
		}
		q.pop();
	}
    
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	int v, e;
	cin >> v >> e;
	int** arr = new int* [v];
	for (int i = 0; i < v; i++)
		arr[i] = new int[v]();
    
	while (e--){
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}
    
	bool* visited = new bool[v];
	for (int i = 0; i < v; i++)
		visited[i] = false;
    
    isConnected(arr, v, 0, visited);
    for (int i = 0; i < v; i++){
        if(!visited[i]){
            cout << "false" <<endl;
            return 0;
        }
    }
    cout << "true" <<endl;       
	return 0;
}


