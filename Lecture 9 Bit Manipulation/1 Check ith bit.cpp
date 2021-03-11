#include<bits/stdc++.h>
using namespace std;

//Let n = 9       n => 00001001   Now to check the ith bit whether it is 0 or 1
// Take &(and) with n and a number whose ith bit is 1
//For ex,  n=9, i=3     n=> 00001001      and    num=> 00001000    this will return true
//For ex,  n=9, i=2     n=> 00001001      and    num=> 00000100    this will return false
bool check(int n, int i){
	return ( n & (1<<i));
}

int main(){
	int n;
	cin >>n;
	int i;
	cin >>i;
	
	if( check(n, i) ){
		cout << 1 << endl;
	} else{
		cout << 0 <<endl;
	}
	
}
