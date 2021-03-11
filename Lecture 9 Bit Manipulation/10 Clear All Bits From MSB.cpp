#include <iostream>
using namespace std;

//You are given two integers N and i. You need to clear all bits from MSB to
// ith bit (start i from right to left) and return the updated N.
//Counting of bits starts from 0 from right to left.
//Take a number whose bits are 1 from 0th to ith index(right to left), and rest are zero
//Now, take & of n and m   to have the desired output.

//Let i = 4  then  m should be m=> 00..000111   to make m like this foolow teh steps
// Let a  = 1 << i =>   a =>   00..001000        now  m = a-1    m=> 00..000111
int clearAllBits(int n, int i){
    int m = (1 << i) -1;
    int ans = n&m;
    return ans;
}

int main() {
	int n, i;
	cin >> n >> i;
	cout<< clearAllBits(n, i) <<endl;
	return 0;
}
