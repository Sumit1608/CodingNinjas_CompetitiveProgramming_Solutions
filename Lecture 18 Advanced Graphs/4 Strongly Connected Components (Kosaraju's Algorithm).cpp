#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
int const mod = 1000000007;

// KOSARAJU's Algorithm
// Time comp => O(V+E)

void dfs(vector<int> *edges, int start, unordered_set<int> &visited, stack<int> &finishVertices){
	visited.insert(start);
	for(int i=0; i < edges[start].size(); i++){
		int adjacent = edges[start][i];
		if(visited.count(adjacent) == 0){
			dfs(edges, adjacent, visited, finishVertices);
		}
	}
	finishVertices.push(start);
}


void dfs2(vector<int> *transpose, int start, unordered_set<int> *component, unordered_set<int> &visited){
	visited.insert(start);
	component->insert(start);
	for(int i=0; i < transpose[start].size(); i++){
		int adjacent = transpose[start][i];
		if(visited.count(adjacent) == 0){
			dfs2(transpose, adjacent, component, visited);
		}
	}
}


unordered_set<unordered_set<int>*>* getSCC(vector<int> *edges, vector<int> *transpose, int n){
	unordered_set<int> visited;
	stack<int> finishVertices;
	
	for(int i=0; i<n; i++){
		if(visited.count(i) == 0){
			dfs(edges, i, visited, finishVertices);
		}
	}
	visited.clear();
	
	unordered_set<unordered_set<int>*>* output = new unordered_set<unordered_set<int>*>();
	while(finishVertices.size() != 0){
		int element = finishVertices.top();
		finishVertices.pop();
		if(visited.count(element) == 0){
			unordered_set<int> *component = new unordered_set<int>();
			dfs2(transpose, element, component, visited);
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
    vector<int> *transpose = new vector<int>[n];
    int m;
    cin >> m;
    for(int i=0; i<m; i++){
    	int j, k;
    	cin >> j >> k;
    	edges[j-1].push_back(k-1);
    	transpose[k-1].push_back(j-1);
	}
	
	unordered_set<unordered_set<int>*> *components = getSCC(edges, transpose, n);
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
	delete transpose;
    return 0;
}

