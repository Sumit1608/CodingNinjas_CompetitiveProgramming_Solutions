#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

//time comp=> O(n)
int main(){
	int n,k,x;
	cin>>n>>k>>x;
	
	long oneCount = 1;
	long nonOneCount = 0;
	
	for(int i=1; i<n; i++){
		long prevOneCount = oneCount;
		oneCount = (nonOneCount * (k-1)) % mod;
		nonOneCount = (prevOneCount + (nonOneCount * (k-2))%mod )%mod;
	}
	
	if(x == 1){
		cout << oneCount <<endl;
	} else{
		cout << nonOneCount <<endl;
	}
}


