#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
int const mod = 1000000007;

int bfs(vector<int> edges[], int n){
	bool *visited = new bool[n]();
	int *ans = new int[n+1]();
	
	queue<int> q;
	q.push(0);
	visited[0] = true;
	
	while(!q.empty()){
		int currNode = q.front();
		q.pop();
		for(int i=0; i<edges[currNode].size(); i++){
			int next = edges[currNode][i];
			if(!visited[next]){
				q.push(next);
				visited[next] = true;
				ans[next] = ans[currNode]+1;
			}
		}
	}
	return ans[n-1];
}

int main(){
    int t;
    cin >> t;
    while (t--){
        int n, m;
        cin >> n >> m;
        vector<int> edges[n];
        for(int i=0; i<m; i++){
        	int a, b;
        	cin >> a >> b;
        	edges[a-1].push_back(b-1);
        	edges[b-1].push_back(a-1);
		}
		
		cout << bfs(edges, n) << endl;
    }
    return 0;
}


