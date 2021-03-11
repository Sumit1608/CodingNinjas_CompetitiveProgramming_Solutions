#include<bits/stdc++.h>
using namespace std;

//Let n = 9       n => 00001001   Now to turn off the ith bit, check the ith bit, if it is 1, then subtrat 
// the number, otherwise return it
//For ex,  n=9, i=3     n=> 00001001      and    num=> 00001000    this will return 1 (00000001)
//For ex,  n=9, i=2     n=> 00001001    2nd bit is 0, so this will return 9 (00001001)
int turnOffIthBit(int n, int i){
    int temp = n;
    temp = temp & (1 << i);
    if(temp != 0){
        n = n - (1<< i);
    }
    return n;
}

int main(){
	int n;
	cin >>n;
	int i;
	cin >>i;
	
	cout << turnOffIthBit(n,i) <<endl;
}
