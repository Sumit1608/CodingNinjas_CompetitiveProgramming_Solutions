#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
int const mod = 1000000007;

// time comp => O(N)

/* Using Grpah

int x,n,t; 
vector<int> adj[300010]; 
bool visited[300010]; 
void dfs(int i) {
	visited[i]=true;
	for (int j: adj[i]) {
		if (!visited[j]) {
			dfs(j);
		}
	}
}

int main() {
	memset(visited,false,sizeof visited);
	cin>>n>>t;
	for (int i=1; i<n; i++) {
		cin>>x;
		adj[i].push_back(x+i);
	}
	dfs(1);
	if (visited[t])
		cout<<"YES"<<endl; 
	else 
		cout<<"NO"<<endl; 
}

*/

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, t;
    cin >> n >> t;
    t--;
    int arr[n];
    for(int i=0; i<n-1; i++){
    	cin >> arr[i];
	}
	
	int ans = false;
	int i=0;
	while(i < n-1){
		if(t == i){
			ans = true;
			break;
		}
		i += arr[i];
	}
	
	if (ans)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}


