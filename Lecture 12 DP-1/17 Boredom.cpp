#include<iostream>
#include<vector>
using namespace std;

//Time comp => O(n)
int solve(int n,vector<int>A){
    int dp[1001] ={0};
    int freq[1001] = {0};
    // Count the frequency of each integer
    for(int i=0; i<n; i++){
        freq[A[i]]++;
    }
    
    dp[0] = 0;
    dp[1] = freq[1];
    // Dp[i] denotes the max points when i is the highest integer to be removed
    for(int i=2; i<=1000; i++){
    	//either we take ith element, so we take sum of i-2 numbers with i*frequency of it   
		//or  we don't take ith number, then i-1 numbers will be our result, take the max of these two
        dp[i] = max(dp[i-1], freq[i]*i +dp[i-2] );
    }
    return dp[1000];
}

int main(){
	int n;
	vector<int>A;
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		A.push_back(x);
	}
	cout<<solve(n,A)<<endl;
}
