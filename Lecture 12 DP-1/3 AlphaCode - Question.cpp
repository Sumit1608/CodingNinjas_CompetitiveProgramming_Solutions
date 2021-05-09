#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

//Time com => O(n)
// Temp stores the no of codes possibe for i numbers at ith index
// if there is 0, for example, 201,   then store 20 as a single number,  we can't take 2 and 0 as
// separate numbers,    and  if a number is like   30 or 200,   then return 0

long long numcodes(int arr[], int n){
    long long temp[n+1] = {0};
    temp[0] = 1;
    temp[1] = 1;
    
    int i=2;
    while (i <= n) {
        if(arr[i-1] > 0)
          	temp[i] = temp[i-1];
        
        int sum = arr[i-2]*10 + arr[i-1];
        
        if(sum <= 26 && arr[i-2] > 0)
	    	temp[i] = (temp[i] + temp[i-2])%mod;
        i++;
    }
	return temp[n];
}


int main(){
    string s;
    cin>>s;
    
    while(s != "0"){
        int n = s.size();
        int arr[n];
        for(int i=0; i<n; i++){
            arr[i] = s[i]-'0';
        }
        
        cout <<numcodes(arr, n)<<endl;
        cin>>s;
    }
}
