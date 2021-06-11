#include<bits/stdc++.h>
using namespace std;

// take a node and use dfs/bfs to find it's connecting node
// now, if a node is not connected, then again call the function and increment
// the vale of islands
void islands(int** arr, int n, int starting_vertex, bool* visited){
	queue<int> q;
	q.push(starting_vertex);
	visited[starting_vertex] = true;
    
	while (!q.empty()){
		int current_element = q.front();
		q.pop();
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
    
    int count =0;
    for (int i = 0; i < v; i++){
        if(!visited[i]){
            islands(arr, v, i, visited);
            count++;
        }
    }
    
    cout << count <<endl;       
	return 0;
}


