#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
int const mod = 1000000007;

// Two permutations P and Q are given
// let Q => 5 1 3 2 4 6  and  P => 6 3 1 2 4 5
// Now, it is given that we can swap the no present on indexes (0,1), (1,2) and (2,5)
// We can definitely make P to Q by swapping 
// P => 3 6 1 2 4 5 => 3 1 6 2 4 5 => 3 1 5 2 4 6 => 3 5 1 2 4 6 => 5 3 1 2 4 6 => 5 1 3 2 4 6 = Q
// using (0,1), (1,2) and (2,5) to swap the elements
// By observation if we can swap the elements on (0, 1) and (1,2), then it is posiibly to swap (0,2)
// So, instead of swapping, we can make components of P using the swaps given to us, and
// if the indexes of those components have same numbers for both P and Q then only permutation 
// is possible, otherwise not

void dfs(int start, vector<int> *edges,bool *visited, unordered_set<int> *component){
	if(visited[start])
        return;
        
    visited[start]=true;
    component->insert(start);
    for(vector<int>::iterator it=edges[start].begin(); it!=edges[start].end(); it++)
        if(!visited[*it])
            dfs(*it, edges, visited, component);
    
}

unordered_set<unordered_set<int>*>* getComponents(vector<int> *edges, int n){
	bool *visited = new bool[n]();
	unordered_set<unordered_set<int>*>* output = new unordered_set<unordered_set<int>*>();
	for(int i=0;  i<n; i++){
		if(!visited[i]){
			unordered_set<int> *component = new unordered_set<int>();
			dfs(i, edges,visited, component);
			output->insert(component);
		}
	}
	return output;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
	    int n, m;
	    cin >> n >> m;
	    int *p = new int[n];
	    int *q = new int[n];
	    
	    for(int i=0; i<n; i++)
	    	cin >> p[i];
	    for(int i=0; i<n; i++)
	    	cin >> q[i];
	    
	    vector<int> *edges = new vector<int>[n];
	    for(int i=0; i<m; i++){
	    	int j, k;
	    	cin >> j >> k;
	    	edges[j-1].push_back(k-1);
    		edges[k-1].push_back(j-1);
		}
		
		bool ans = true;
		unordered_set<unordered_set<int>*> *components = getComponents(edges, n);
		unordered_set<unordered_set<int>*>::iterator it = components->begin();
		
		while (it != components->end()) {
			unordered_set<int>* component = *it;
			unordered_set<int>::iterator it2 = component->begin();
			unordered_set<int> pIndex;
			unordered_set<int> qIndex;
			
			while (it2 != component->end()) {
				pIndex.insert(p[*it2]);
				qIndex.insert(q[*it2]);
				it2++;
			}
			if(pIndex != qIndex){
				ans = false;
				break;
			}
			it++;
		}
		
		if(ans)
			cout << "YES" <<endl;
		else
			cout << "NO" << endl;
	}
    return 0;
}

