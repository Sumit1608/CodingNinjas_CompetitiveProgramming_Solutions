#include <iostream>
using namespace std;

//You are given an integer N. You need to return an integer M, in which only one bit
//is set which at position of lowest set bit of N (from right to left).
//So traverse from left to right untill we encounter with the first bit as 1
//Let n = 20  n => 00010100   so we return    num = 4=> 00000100
int returnFirstSetBit(int n){
    if( n == 0){
        return 0;
    }
    int position =1;
    int m=1;
    while( !(n & m) ){
        m = m << 1;
        position = 2*position;
    } return position;
}


int main() {
	int n;

	cin >> n;
	cout<< returnFirstSetBit(n) <<endl;
		
	return 0;
}


