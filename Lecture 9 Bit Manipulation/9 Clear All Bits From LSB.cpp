#include <iostream>
using namespace std;

//You are given two integers N and i. You need to clear all bits from LSB to
// ith bit (start i from right to left) and return the updated N.
//Counting of bits starts from 0 from right to left.
//Take a number whose bits are 0 from 0th to ith index(right to left), and rest are 1
//Now, take & of n and m   to have the desired output.

//Let i = 4  then  m should be m=> 11..110000   to make m like this foolow teh steps
// Let a  = 1 << (i+1) =>   a =>   00..010000        now    c = a-1    c=> 00..001111
// m = ~c      m => 11..110000
int clearAllBits(int n, int i){
    int m = ~((1 << (i+1)) -1);
    int ans = n&m;
    return ans;
}

int main() {
	int n, i;
	cin >> n >> i;
	cout<< clearAllBits(n, i) <<endl;
	return 0;
}
