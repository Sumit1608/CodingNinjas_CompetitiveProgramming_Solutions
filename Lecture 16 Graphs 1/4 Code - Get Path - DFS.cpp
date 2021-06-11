#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
int const mod = 1000000007;

// time comp => O(v^2)
// start searching from the starting vertex, if a node v1 is connected, then call
// recursion on v1, it will search further untill we encounter the ending vertex
// If ending vertex is connected to a node, then it will return a non-ull vector
vector<int> getPathDFS(int **arr, int v, int sv, int ev, bool *visited){
	visited[sv] = true;
    vector<int> vec;
    if(sv == ev){
    	vec.push_back(sv);
        return vec;
    }
    
    visited[sv] = true;
    for(int i=0; i<v; i++){
        if(i == sv || visited[i])
            continue;
        if(arr[sv][i] == 1){
            vec = getPathDFS(arr, v, i, ev, visited);
            if(!vec.empty()){
                vec.push_back(sv);
        		return vec;
            }
        }
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
    vector<int> ans = getPathDFS(arr, v, v1, v2, visited);
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] <<" ";
    }
    
    return 0;
}


