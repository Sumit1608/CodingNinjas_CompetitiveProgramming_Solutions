#include<bits/stdc++.h>
using namespace std;

// time comp => O(n^3)
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	int v, e;
	cin >> v >> e;
	int** arr = new int*[v];
	for (int i = 0; i < v; i++)
		arr[i] = new int[v]();
    
	while (e--){
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}
    
	int cycleCount = 0;
    for (int i = 0; i < v-2; ++i)
        for (int j = i+1; j < v-1; ++j)
            for (int k = j+1; k < v; ++k) 
                if (arr[i][j] && arr[j][k] && arr[k][i])
                    ++cycleCount; 
    
    cout << cycleCount <<endl;       
	return 0;
}


