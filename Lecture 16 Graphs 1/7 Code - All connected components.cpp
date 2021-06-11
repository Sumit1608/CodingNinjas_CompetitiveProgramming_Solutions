#include<bits/stdc++.h>
using namespace std;

vector<int> vector_creator(int** arr, int n, int starting_vertex, bool* visited){
	vector<int>temp;
	queue<int> q;
	q.push(starting_vertex);
	visited[starting_vertex] = true;
    
	while (!q.empty()){
		temp.push_back(q.front());
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
    
	return temp;
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
    
	vector<vector<int> > ans;
	for (int i = 0; i < v; i++)
		if (!visited[i])
			ans.push_back(vector_creator(arr, v, i, visited));
    
	for (int i = 0; i < ans.size(); i++){
		sort(ans[i].begin(), ans[i].end());
		for (int j = 0; j < ans[i].size(); j++){
			cout << ans[i][j]<<" ";
		}
		cout << endl;
	}
    
    return 0;
}


