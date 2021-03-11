#include <iostream>
using namespace std;

//Traverse from right to left untill we found the first bit as 1, then subtract 2^i ( 1 << i) from n
//Let n = 22  n => 00010110   so we return    num = 20=> 00010100
int turnOffFirstSetBit(int n){
    if(n == 0){
        return 0;
    }
    int pos =0;
    int m =1;
    while(!(n & m)){
        m = m << 1;
        pos++;
    }
    n = n - (1 << pos);
    return n;
}

int main() {
	int n;
	cin >> n;
	cout<< turnOffFirstSetBit(n) <<endl;		
	return 0;
}
