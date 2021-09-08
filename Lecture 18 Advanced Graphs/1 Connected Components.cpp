#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
int const mod = 1000000007;

// time comp => O(V+E)
// Choose a vertex v, now insert the vertices connected to it in an set
// if some vertices are not connected, then call for them ans make other set for them
void dfs(int start, vector<int> *edges, int n, bool *visited, unordered_set<int> *component){
	visited[start] = true;
	component->insert(start);
	for(auto &it : edges[start]){
		if(visited[it]){
			continue;
		}
		dfs(it, edges, n, visited, component);
	}
}

unordered_set<unordered_set<int>*>* getComponents(vector<int> *edges, int n){
	bool *visited = new bool[n]();
	unordered_set<unordered_set<int>*>* output = new unordered_set<unordered_set<int>*>();
	for(int i=0;  i<n; i++){
		if(!visited[i]){
			unordered_set<int> *component = new unordered_set<int>();
			dfs(i, edges,n, visited, component);
			output->insert(component);
		}
	}
	return output;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> *edges = new vector<int>[n];
    int m;
    cin >> m;
    for(int i=0; i<m; i++){
    	int j, k;
    	cin >> j >> k;
    	edges[j-1].push_back(k-1);
    	edges[k-1].push_back(j-1);
	}
	
	unordered_set<unordered_set<int>*> *components = getComponents(edges, n);
	unordered_set<unordered_set<int>*>::iterator it = components->begin();
	while (it != components->end()) {
		unordered_set<int>* component = *it;
		unordered_set<int>::iterator it2 = component->begin();
		while (it2 != component->end()) {
			cout << *it2 + 1 << " ";
			it2++;
		}
		cout << endl;
		delete component;
		it++;
	}
	delete components;
	delete edges;
    return 0;
}

