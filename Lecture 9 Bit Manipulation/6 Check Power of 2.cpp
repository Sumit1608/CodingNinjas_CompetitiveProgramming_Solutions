#include<bits/stdc++.h>
using namespace std;

//If any number is a ower of 2,  then only one bit will be 1 and rest will be 0
//So, if we take &(and) with n-1  and the result b=will be 0
//For ex, n=16  n=> 00010000      n-1=15 => 00001111     so if we take n&(n-1), the
//result will be zero for a number which is a power of 2 
bool checkPowerOfTwo(int n){
    return n&(n-1);
}

int main(){
	int n;
	cin >>n;

	if( checkPowerOfTwo(n)){
		cout << "False" << endl;
	} else{
		cout << "True" <<endl;
	}
}
