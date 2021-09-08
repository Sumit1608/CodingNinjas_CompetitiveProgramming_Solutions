#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
int const mod = 1000000007;

//time comp => O(V+E)
/*
There would be 3 cases for this:
1. For an index (i, j) of the matrix a, if (i==j) but a(i, j) =1.
2. For two different indices (i1, j1) and (i2, j2) if(i1=j2) and (i2=j1) but a(i1, j1)! =a(i2, j2).
3. For three different indices if any two of them have one common index (i, j) 
then the number of 1’s at these three indices should not be 1 or 3. Eg. If three 
indices are (1,2), (1,4), (2,4) here for any two indices 1 index(i or j) is common.
Then for this 1 should not be at all the three positions or there should not be only
one 1 at any of these 3 indices.
*/


const int N = 1e5 + 5;
bool error;
int col[N];
vector<pair<int, int> > adj[N];

void dfs(int start){
//    for (auto edge : adj[start]){
	for(int i=0; i<adj[start].size(); i++){
		pair<int, int> edge = adj[start][i];
        int next = edge.first;
        if (col[next] == -1){
            col[next] = col[start] ^ edge.second;
            dfs(next);
        }
        else if (col[next] != col[start] ^ edge.second)
            error = true;
    }
}

int main(){
    int t;
    cin >> t;
    while (t--){
        int n, m;
        cin >> n >> m;
        error = false;
        for (int i = 1; i <= n; i++){
            adj[i].clear();
            col[i] = -1;
        }
        while (m--){
            int a, b, c;
            cin >> a >> b >> c;
            adj[a].push_back(make_pair(b, c));
            adj[b].push_back(make_pair(a, c));
        }
        for (int i = 1; i <= n; i++){
            if (col[i] == -1){
                col[i] = 0;
                dfs(i);
            }
        }
        if (error)
            cout << "no" << endl;
        else
            cout << "yes" << endl;
    }
}


