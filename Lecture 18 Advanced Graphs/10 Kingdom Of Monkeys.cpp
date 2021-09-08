#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
int const mod = 1000000007;

ll bfs(vector<int> edges[], bool *visited, int start, ll *arr){
	queue<int> q;
	q.push(0);
	visited[0] = true;
	ll ans = 0;
	
	while(!q.empty()){
		int currNode = q.front();
		ans += arr[currNode];
		q.pop();
		for(int i=0; i<edges[currNode].size(); i++){
			int next = edges[currNode][i];
			if(!visited[next]){
				q.push(next);
				visited[next] = true;
			}
		}
	}
	return ans;
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
		ll* arr = new ll[n];
        for (ll i = 0; i < n; i++)
            cin >> arr[i];
        
		bool *visited = new bool[n]();
		ll ans =0;
		for(int i=0; i<n; i++){
			if(!visited[i]){
				ll smallAns = bfs(edges, visited, i, arr);
				if(smallAns > ans)
					ans = smallAns;
			}
		}
		
		cout << ans << endl;
    }
    return 0;
}


// Using DFS
/*
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
typedef long long int ll;

ll dfs(vector<ll>* edges, ll* arr, ll n, bool* visited, ll start){
    ll sum = arr[start];
    visited[start] = true;
    for (ll i = 0; i < edges[start].size(); i++){
        ll adjacent = edges[start][i];
        if (!visited[adjacent])
            sum += dfs(edges, arr, n, visited, adjacent);
    }
    return sum;
}

int main(){
    ll t;
    cin >> t;
    while (t--){
        ll n, m;
        cin >> n >> m;
        vector<ll>* edges = new vector<ll>[n];
        for (ll i = 0; i < m; i++){
            ll x, y;
            cin >> x >> y;
            edges[x - 1].push_back(y - 1);
            edges[y - 1].push_back(x - 1);
        }
        
        ll* arr = new ll[n];
        for (ll i = 0; i < n; i++)
            cin >> arr[i];
        bool* visited = new bool[n];
        for (ll i = 0; i < n; i++)
            visited[i] = false;
        
        ll maximum = INT_MIN;
        for (ll i = 0; i < n; i++){
            if (!visited[i]){
                ll current_component_total_bananas = dfs(edges, arr, n, visited, i);
                if (current_component_total_bananas > maximum)
                    maximum = current_component_total_bananas;
            }
        }
        cout << maximum << endl;
    }
    
}

*/
