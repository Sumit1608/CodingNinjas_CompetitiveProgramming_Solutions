#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
int const mod = 1000000007;

// time comp => O(v^2)
// start searching from the starting vertex, if a node v1 is connected, then insert the 
// the path current node to ith node in a map, it will store all the paths we encounter
// search further untill we encounter the ending vertex
// If ending vertex is connected to a node, then break the loop and insert the nodes in reverse
// order using the hashmap

vector<int> getPathBFS(int **arr, int v, int sv, int ev, bool *visited){
    vector<int> vec;
	visited[sv] = true;
	queue<int> q;
	q.push(sv);
//    unordered_map<int, int> m;
	map<int, int> m;
    
    while (!q.empty()){
		int current = q.front();
		if (current == ev){
			break;
		}
		for (int i = 0; i < v; i++){
			if (!visited[i] && arr[current][i] == 1 && i !=current){
				q.push(i);
				visited[i] = true;
				m[i] = current;
			}
		}
		q.pop();
		if (q.empty()){
			return vec;
		}
	}
    
	int i = ev;
    vec.push_back(ev);
	while ( i != sv){
        vec.push_back(m[i]);
		i = m[i];
	}
	return vec;
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
    vector<int> ans = getPathBFS(arr, v, v1, v2, visited);
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] <<" ";
    }
    
    return 0;
}


