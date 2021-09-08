#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
int const mod = 1000000007;


// time comp => O(N*M)
// Like the previous problem, if we can swap two set of horses h1 with h2
// and h2 with h3, then we can swap h3 with h1 also,  and the no of possible such
// permutation will be factorial of (no of horses that can be swapped with each other)
// So find the no of vertices in each component and multiply the ans with the factorial of those number
ll fact(ll t){
	int ans = 1;
	for (ll i = 1; i <= t; i++)
		ans = (ans * i) % mod;
	return ans;
}

ll bfs(int **arr, int i, int j, int n, int m){
	ll smallAns = 1;
	arr[i][j] = 0;
	
	if (i - 2 >= 1 && j + 1 <= m && arr[i - 2][j + 1] == 1)
		smallAns += bfs(arr, i-2, j+1, n, m);
	if (i - 2 >= 1 && j - 1 >= 1 && arr[i - 2][j - 1] == 1)
		smallAns += bfs(arr, i-2, j-1, n, m);
	
	if (i + 2 <= n && j + 1 <= m && arr[i + 2][j + 1] == 1)
		smallAns += bfs(arr, i+2, j+1, n, m);
	if (i + 2 <= n && j - 1 >= 1 && arr[i + 2][j - 1] == 1)
		smallAns += bfs(arr, i+2, j-1, n, m);

	if (i - 1 >= 1 && j + 2 <= m && arr[i - 1][j + 2] == 1)
		smallAns += bfs(arr, i-1, j+2, n, m);
	if (i - 1 >= 1 && j - 2 >= 1 && arr[i - 1][j - 2] == 1)
		smallAns += bfs(arr, i-1, j-2, n, m);
		
	if (i + 1 <= n && j + 2 <= m && arr[i + 1][j + 2] == 1)
		smallAns += bfs(arr, i+1, j+2, n, m);
	if (i + 1 <= n && j - 2 >= 1 && arr[i + 1][j - 2] == 1)
		smallAns += bfs(arr, i+1, j-2, n, m);
	
	return smallAns;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
    	int ans = 1;
    	int n, m, q;
    	cin >> n >> m >> q;
    	int **arr = new int*[n+1];
    	for(int i=0; i<=n; i++)
    		arr[i] = new int[m+1]();
    	
    	for(int i=0; i<q; i++){
    		int a, b;
    		cin >> a>> b;
    		arr[a][b] = 1;
		}
		
		for(int i=0; i<=n; i++){
			for(int j=0; j<=m; j++){
				if(arr[i][j] == 1){
					ll t = bfs(arr, i, j, n, m);
					ans = (ans*fact(t))%mod;
				}
			}
		}
		cout << ans << endl;
	}
    return 0;
}

