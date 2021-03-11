#include<bits/stdc++.h>
using namespace std;

//Check the last bit of number, if 1 the it is odd, otherwise even
bool checkOddEven(int n){
    return (n&1);
}

int main(){
	int n;
	cin >>n;

	if( checkOddEven(n)){
		cout << "Odd" << endl;
	} else{
		cout << "Even" <<endl;
	}
}
