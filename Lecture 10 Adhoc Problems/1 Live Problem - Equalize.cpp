#include<bits/stdc++.h>
using namespace std;

//Time Comp => O(n)
//  let s = 110100  and t = 010101   Now, if we just flip the bits of s to make 
// it equal t, then we reuire  cost = no of bits different
// but if two bits are adjacent and we swap them to make it equa to t, then we require
// cost = 1 for two bits.  So, we swap the bits of s when the adjacent bits are not equal 
// and so with the bits of t.   For example,  s = 1000 and t = 0100   here s[i] and s[i+1] 
// are not equal and so do s[i+1] and t[i+1]      so we swap them, otherwise just flip the bits.

int main(){
	int n;
	cin >>n;
	string a,b;
	cin >>a >> b;
	
	int i=0, cost =0;;
	while(i <n){
		if(a[i] != b[i]){
			//swap condition
			if(i+1<n && a[i] != a[i+1] && a[i+1] != b[i+1]){
				cost++;
				i += 2;
			} else{
				cost++;
				i++;
			}
		}
		else{
			i++;
		}
	}
	
	cout << cost <<endl;
}
