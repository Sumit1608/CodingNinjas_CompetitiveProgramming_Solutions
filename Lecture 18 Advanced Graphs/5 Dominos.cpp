#include <bits/stdc++.h> 
using namespace std; 

stack<int> st; 
vector<int> adjList[100010]; 
bool visited[100010]; 

// Time comp => O(V+E)
//We first find out all the strongly connected components. After finding out, 
//it is a DAG, and each component is regarded as a point, because if any card in 
//the card falls, all the cards in it will fall. Then at this time, as many points 
//as the score is equal to 0, you need to manually push down how many cards.

void dfs2(int index){
	visited[index]=true;
	for(unsigned int j=0;j<adjList[index].size();j++){
		if(!visited[adjList[index][j]]){
			dfs2(adjList[index][j]);
		}
	}
}

void dfs(int index){
	visited[index]=true;
	for(unsigned int j=0;j<adjList[index].size();j++){
		if(!visited[adjList[index][j]]){
			dfs(adjList[index][j]);
		}
	}
	st.push(index);
}

int main(){ 
	int t;
	cin >> t;
	
	while(t--){
		memset(visited, 0, sizeof(visited));
		int n, m;
		cin >> n >>m;
		for(int i=0; i<m; i++){
			int a,b;
			cin >> a >> b;
			adjList[a].push_back(b);
		}
		
		for(int i=1; i<=n; i++){
			if( !visited[i] )
				dfs(i);
		}
		
		memset(visited, 0, sizeof(visited));
		int count =0;
		
		while( !st.empty() ){
			int index = st.top();
			st.pop();
			if( !visited[index] ){
				count++;
				dfs2(index);
			}
		}
		
		cout << count <<endl;
		for(int i=0; i<=n; i++){
			adjList[i].clear();
		}
	}
	
	return 0; 
}






