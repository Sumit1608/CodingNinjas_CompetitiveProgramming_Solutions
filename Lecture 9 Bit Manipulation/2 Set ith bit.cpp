#include<bits/stdc++.h>
using namespace std;

//Let n = 9       n => 00001001   Now to turn on the ith bit, take |(or) with n and a number whose ith bit is 1
//For ex,  n=9, i=3     n=> 00001001      and    num=> 00001000    this will return 9 (00001001)
//For ex,  n=9, i=2     n=> 00001001      and    num=> 00000100    this will return 13 (00001101)
int turnOnIthBit(int n, int i){
    n = (n | (1 << i) );
    return n;
}

int main(){
	int n;
	cin >>n;
	int i;
	cin >>i;
	
	cout << turnOnIthBit(n,i) <<endl;
}
